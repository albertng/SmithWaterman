GAP_OPEN_PENALTY = -2
GAP_EXTEND_PENALTY = -1
SUB_PENALTY = [[10, -2, -2, -2], [-2, 10, -2, -2], [-2, -2, 10, -2], [-2, -2, -2, 10]]

NUCLEOTIDES = ['A', 'C', 'G', 'T']

def NtSeq2IntArray(seq):
    int_array = []
    for nt in seq:
        if nt in NUCLEOTIDES:
            int_array.append(NUCLEOTIDES.index(nt))
        else:
            int_array.append(-1)
    return int_array

#short_read = NtSeq2IntArray("GCAGCT")
#short_read = NtSeq2IntArray("ACACTA")
#short_read = NtSeq2IntArray("ACTAGC")
short_read = NtSeq2IntArray("AGCA")
reference = NtSeq2IntArray("CAGCAGTAAGCAGTAA")
#reference  = NtSeq2IntArray("ACAGACTATGCT")
#reference  = NtSeq2IntArray("ACAGACTAAA")
#reference  = NtSeq2IntArray("ATAGTCAT")
#reference  = NtSeq2IntArray("ATAGTCAC")

def FeedV():
    return 0
    
def FeedF():
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
        self.T_d = 0        
        self.T_q = 0  
        self.max_d = 0
        self.max_q = 0
        self.V_diag_d = 0
        self.V_diag_q = 0
        self.V_d = 0
        self.V_q = 0
        self.E_d = 0
        self.E_q = 0
        self.F_d = 0
        self.F_q = 0
        self.init_d = 0
        self.init_q = 0    

        # Input port connections
        self.getLeftVFn = ""
        self.getLeftFFn = ""
        self.getTFn = ""
        self.getMaxFn = ""
        self.getInitFn = ""

    def GetV(self):
        return self.V_q

    def GetF(self):
        return self.F_q

    def GetT(self):
        return self.T_q

    def GetMax(self):
        return self.max_q

    def GetInit(self):
        return self.init_q

    def Max(self, values):
        max = float("-inf")
        for val in values:
            if val > max:
                max = val
        return max
        
    def Compute(self):
        leftV = self.getLeftVFn()
        leftF = self.getLeftFFn()
        leftT = self.getTFn()
        leftMax = self.getMaxFn()
        leftinit = self.getInitFn()

        if leftinit == 0:
            self.E_d = 0
            self.F_d = 0
            self.V_d = 0
        else :
            self.E_d = self.Max([self.V_q + GAP_OPEN_PENALTY, self.E_q + GAP_EXTEND_PENALTY])
            self.F_d = self.Max([leftV + GAP_OPEN_PENALTY, leftF + GAP_EXTEND_PENALTY])
            self.V_d = self.Max([0, self.E_d, self.F_d, self.V_diag_q + SUB_PENALTY[self.S][leftT]])

        self.max_d = self.Max([self.max_q, leftMax, self.V_d])

        self.V_diag_d = leftV
        self.T_d = leftT
        self.init_d = leftinit
    def Clock(self):
        self.V_diag_q = self.V_diag_d
        self.V_q = self.V_d
        self.E_q = self.E_d
        self.F_q = self.F_d
        self.T_q = self.T_d
        self.max_q = self.max_d
        self.init_q = self.init_d

PEs = [SmithWatermanPE(short_read[i]) for i in range(len(short_read))]
PEs[0].getLeftVFn = FeedV
PEs[0].getLeftFFn = FeedF
PEs[0].getTFn = FeedT
PEs[0].getMaxFn = FeedMax
PEs[0].getInitFn = FeedInit
for i in range(1, len(PEs)):
    PEs[i].getLeftVFn = PEs[i-1].GetV    
    PEs[i].getLeftFFn = PEs[i-1].GetF    
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
        outstr += str(PE.V_q) + "\t"
    print outstr
print(PEs[-1].GetMax())
