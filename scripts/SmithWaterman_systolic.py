GAP_PENALTY = -1
SUB_PENALTY = [[2, -1, -1, -1], [-1, 2, -1, -1], [-1, -1, 2, -1], [-1, -1, -1, 2]]

NUCLEOTIDES = ['A', 'C', 'G', 'T']

def NtSeq2IntArray(seq):
    int_array = []
    for nt in seq:
        if nt in NUCLEOTIDES:
            int_array.append(NUCLEOTIDES.index(nt))
        else:
            int_array.append(-1)
    return int_array

short_read = NtSeq2IntArray("ACAGACTA")
reference  = NtSeq2IntArray("AGCACACA")

def FeedScore():
    return 0

def FeedT():
    FeedT.index += 1
    if (FeedT.index < len(reference)):
        return reference[FeedT.index]
    else:
        return 0
FeedT.index = -1

def FeedMax():
    return 0

def FeedInit():
    if FeedInit.index < len(reference):
        FeedInit.index += 1
        return 1
    else:
        return 0
FeedInit.index = 0

class SmithWatermanPE:
    def __init__(self, S):
        # Member variables
        self.S = S

        # Local states
        self.prevScore_d = 0
        self.prevScore_q = 0
        self.diagScore_d = 0    
        self.diagScore_q = 0    
        self.T_d = 0        
        self.T_q = 0    
        self.max_d = 0
        self.max_q = 0
        self.init_d = 0
        self.init_q = 0    

        # Input port connections
        self.getLeftScoreFn = ""
        self.getTFn = ""
        self.getMaxFn = ""
        self.getInitFn = ""

    def GetScore(self):
        return self.prevScore_q

    def GetT(self):
        return self.T_q

    def GetMax(self):
        return self.max_q

    def GetInit(self):
        return self.init_q

    def Compute(self):
        leftScore = self.getLeftScoreFn()
        init = self.getInitFn()

        deletionScore = leftScore + GAP_PENALTY
        insertionScore = self.prevScore_q + GAP_PENALTY
        T = self.getTFn()
        matchScore = self.diagScore_q + SUB_PENALTY[self.S][T]
        
        if deletionScore > insertionScore and deletionScore > matchScore:
            finalScore = deletionScore
        elif insertionScore > deletionScore and insertionScore > matchScore:
            finalScore = insertionScore
        else:
            finalScore = matchScore
        if finalScore < 0:
            finalScore = 0
        if init == 0:
            finalScore = 0

        prevPEMax = self.getMaxFn()
        if prevPEMax > self.max_q and prevPEMax > finalScore:
            self.max_d = prevPEMax
        elif self.max_q > prevPEMax and self.max_q > finalScore:
            self.max_d = self.max_q
        else:
            self.max_d = finalScore

        self.diagScore_d = leftScore
        self.prevScore_d = finalScore
        self.T_d = T
        self.init_d = init
    def Clock(self):
        self.prevScore_q = self.prevScore_d
        self.diagScore_q = self.diagScore_d
        self.T_q = self.T_d
        self.max_q = self.max_d
        self.init_q = self.init_d

PEs = [SmithWatermanPE(short_read[i]) for i in range(len(short_read))]
PEs[0].getLeftScoreFn = FeedScore
PEs[0].getTFn = FeedT
PEs[0].getMaxFn = FeedMax
PEs[0].getInitFn = FeedInit
for i in range(1, len(PEs)):
    PEs[i].getLeftScoreFn = PEs[i-1].GetScore    
    PEs[i].getTFn = PEs[i-1].GetT
    PEs[i].getMaxFn = PEs[i-1].GetMax
    PEs[i].getInitFn = PEs[i-1].GetInit
for i in range(len(short_read) + len(reference) - 1):
    for PE in PEs:
        PE.Compute()
    for PE in PEs:
        PE.Clock()
    outstr = ""
    for PE in PEs:
        outstr += str(PE.prevScore_q) + " "
    print(outstr)
print(PEs[-1].GetMax())
