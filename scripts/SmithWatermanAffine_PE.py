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

short_read = NtSeq2IntArray("ACACTA")
reference  = NtSeq2IntArray("ACAGACTA")

def FeedV0():
    return 0
    
def FeedV10():
    return 10

def FeedF0():
    return 0

def FeedF_4():
    return -4

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

print "V=0, F=0, S='A' test"
FeedT.index = -1
FeedInit.index = 0
PE = SmithWatermanPE(short_read[0])
PE.getLeftVFn = FeedV0
PE.getLeftFFn = FeedF0
PE.getTFn = FeedT
PE.getMaxFn = FeedMax
PE.getInitFn = FeedInit
for i in range(len(reference)):
    PE.Compute()
    PE.Clock()
    print PE.GetV(), PE.GetF(), PE.GetT(), PE.GetInit()

print "\nV=0, F=0, S='C' test"
FeedT.index = -1
FeedInit.index = 0
PE = SmithWatermanPE(short_read[1])
PE.getLeftVFn = FeedV0
PE.getLeftFFn = FeedF0
PE.getTFn = FeedT
PE.getMaxFn = FeedMax
PE.getInitFn = FeedInit
for i in range(len(reference)):
    PE.Compute()
    PE.Clock()
    print PE.GetV(), PE.GetF(), PE.GetT(), PE.GetInit()

print "\nV=10, F=-4, S='T' test"
FeedT.index = -1
FeedInit.index = 0
PE = SmithWatermanPE(short_read[4])
PE.getLeftVFn = FeedV10
PE.getLeftFFn = FeedF_4
PE.getTFn = FeedT
PE.getMaxFn = FeedMax
PE.getInitFn = FeedInit
for i in range(len(reference)):
    PE.Compute()
    PE.Clock()
    print PE.GetV(), PE.GetF(), PE.GetT(), PE.GetInit()
