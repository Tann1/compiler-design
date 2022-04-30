.class public Hilbert
.super java/lang/Object

.field private static _sysin Ljava/util/Scanner;
.field private static h [[F
.field private static hinv [[F
.field private static i I
.field private static j I
.field private static n I
.field private static ps [I
.field private static z [[F

;
; Runtime input scanner
;
.method static <clinit>()V

	new	java/util/Scanner
	dup
	getstatic	java/lang/System/in Ljava/io/InputStream;
	invokespecial	java/util/Scanner/<init>(Ljava/io/InputStream;)V
	putstatic	Hilbert/_sysin Ljava/util/Scanner;
	return

.limit locals 0
.limit stack 3
.end method

;
; Main class constructor
;
.method public <init>()V
.var 0 is this LHilbert;

	aload_0
	invokespecial	java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
.end method

;
; PROCEDURE singular
;
.method private static singular(I)V

.var 0 is w I
;
; 030 CASEwOFSINGULARMATRIX:writeln('Singular matrix in decompose.');ZEROROW ...
;
	iload_0
	lookupswitch
	  0: L002
	  1: L003
	  2: L004
	  default: L001
L002:
;
; 031 writeln('Singular matrix in decompose.')
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"Singular matrix in decompose.\n"
	invokevirtual	java/io/PrintStream/print(Ljava/lang/String;)V
	goto	L001
L003:
;
; 032 writeln('Matrix with zero row in decompose.')
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"Matrix with zero row in decompose.\n"
	invokevirtual	java/io/PrintStream/print(Ljava/lang/String;)V
	goto	L001
L004:
;
; 033 writeln('No convergence in improve.')
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"No convergence in improve.\n"
	invokevirtual	java/io/PrintStream/print(Ljava/lang/String;)V
	goto	L001
L005:
	goto	L001
L001:

	return

.limit locals 1
.limit stack 2
.end method

;
; FUNCTION abs
;
.method private static abs(F)F

.var 1 is abs F
.var 0 is x F
;
; 040 IFx<0THENx:=-x
;
	fload_0
	iconst_0
	i2f
	fcmpg
	iflt	L008
	iconst_0
	goto	L009
L008:
	iconst_1
L009:
	iconst_0
	if_icmpeq	L007
;
; 040 x:=-x
;
	fload_0
	fneg
	fstore_0
L007:
;
; 041 abs:=x
;
	fload_0
	fstore_1

	fload_1
	freturn

.limit locals 2
.limit stack 2
.end method

;
; PROCEDURE decompose
;
.method private static decompose(I[[F[[F)V

.var 1 is a [[F
.var 11 is biggest F
.var 4 is i I
.var 5 is j I
.var 6 is k I
.var 2 is lu [[F
.var 12 is mult F
.var 0 is n I
.var 8 is normrow F
.var 9 is pivot F
.var 7 is pivotindex I
.var 3 is scales [F
.var 10 is size F

	iconst_5
	newarray	float
	astore_3
;
; 059 FORi:=1TOnDOBEGINps[i]:=i;normrow:=0;FORj:=1TOnDOBEGINLU[i,j]:=A[i,j]; ...
;
	iconst_1
	istore	4
L010:
	iload_0
	iconst_1
	iadd
	iload	4
	if_icmpeq	L011
;
; 060 ps[i]:=i
;
	getstatic	Hilbert/ps [I
	iload	4
	iconst_1
	isub
	iload	4
	iastore
;
; 061 normrow:=0
;
	iconst_0
	i2f
	fstore	8
;
; 063 FORj:=1TOnDOBEGINLU[i,j]:=A[i,j];IFnormrow<abs(LU[i,j])THENnormrow:=ab ...
;
	iconst_1
	istore	5
L012:
	iload_0
	iconst_1
	iadd
	iload	5
	if_icmpeq	L013
;
; 064 LU[i,j]:=A[i,j]
;
	aload_2
	iload	4
	iconst_1
	isub
	aaload
	iload	5
	iconst_1
	isub
	aload_1
	iload	4
	iconst_1
	isub
	aaload
	iload	5
	iconst_1
	isub
	faload
	fastore
;
; 067 IFnormrow<abs(LU[i,j])THENnormrow:=abs(LU[i,j])
;
	fload	8
	aload_2
	iload	4
	iconst_1
	isub
	aaload
	iload	5
	iconst_1
	isub
	faload
	invokestatic	Hilbert/abs(F)F
	fcmpg
	iflt	L016
	iconst_0
	goto	L017
L016:
	iconst_1
L017:
	iconst_0
	if_icmpeq	L015
;
; 067 normrow:=abs(LU[i,j])
;
	aload_2
	iload	4
	iconst_1
	isub
	aaload
	iload	5
	iconst_1
	isub
	faload
	invokestatic	Hilbert/abs(F)F
	fstore	8
L015:
	iload	5
	iconst_1
	iadd
	istore	5
	goto	L012
L013:
;
; 071 IFnormrow<>0THENscales[i]:=1/normrowELSEBEGINscales[i]:=0;singular(ZER ...
;
	fload	8
	iconst_0
	i2f
	fcmpg
	ifne	L020
	iconst_0
	goto	L021
L020:
	iconst_1
L021:
	iconst_0
	if_icmpeq	L018
;
; 071 scales[i]:=1/normrow
;
	aload_3
	iload	4
	iconst_1
	isub
	iconst_1
	i2f
	fload	8
	fdiv
	fastore
	goto	L019
L018:
;
; 073 scales[i]:=0
;
	aload_3
	iload	4
	iconst_1
	isub
	iconst_0
	i2f
	fastore
;
; 074 singular(ZEROROW)
;
	iconst_1
	invokestatic	Hilbert/singular()V
L019:
	iload	4
	iconst_1
	iadd
	istore	4
	goto	L010
L011:
;
; 079 FORk:=1TOn-1DOBEGINpivotindex:=0;biggest:=0;FORi:=kTOnDOBEGINsize:=abs ...
;
	iconst_1
	istore	6
L022:
	iload_0
	iconst_1
	isub
	iconst_1
	iadd
	iload	6
	if_icmpeq	L023
;
; 080 pivotindex:=0
;
	iconst_0
	istore	7
;
; 081 biggest:=0
;
	iconst_0
	i2f
	fstore	11
;
; 084 FORi:=kTOnDOBEGINsize:=abs(LU[ps[i],k])*scales[ps[i]];IFbiggest<sizeTH ...
;
	iload	6
	istore	4
L024:
	iload_0
	iconst_1
	iadd
	iload	4
	if_icmpeq	L025
;
; 087 size:=abs(LU[ps[i],k])*scales[ps[i]]
;
	aload_2
	getstatic	Hilbert/ps [I
	iload	4
	iconst_1
	isub
	iaload
	iconst_1
	isub
	aaload
	iload	6
	iconst_1
	isub
	faload
	invokestatic	Hilbert/abs(F)F
	aload_3
	getstatic	Hilbert/ps [I
	iload	4
	iconst_1
	isub
	iaload
	iconst_1
	isub
	faload
	fmul
	fstore	10
;
; 089 IFbiggest<sizeTHENBEGINbiggest:=size;pivotindex:=i;END
;
	fload	11
	fload	10
	fcmpg
	iflt	L028
	iconst_0
	goto	L029
L028:
	iconst_1
L029:
	iconst_0
	if_icmpeq	L027
;
; 090 biggest:=size
;
	fload	10
	fstore	11
;
; 091 pivotindex:=i
;
	iload	4
	istore	7
L027:
	iload	4
	iconst_1
	iadd
	istore	4
	goto	L024
L025:
;
; 095 IFbiggest=0THENsingular(SINGULARMATRIX)ELSEBEGINIFpivotindex<>kTHENBEG ...
;
	fload	11
	iconst_0
	i2f
	fcmpg
	ifeq	L032
	iconst_0
	goto	L033
L032:
	iconst_1
L033:
	iconst_0
	if_icmpeq	L030
;
; 095 singular(SINGULARMATRIX)
;
	iconst_0
	invokestatic	Hilbert/singular()V
	goto	L031
L030:
;
; 097 IFpivotindex<>kTHENBEGINj:=ps[k];ps[k]:=ps[pivotindex];ps[pivotindex]: ...
;
	iload	7
	iload	6
	if_icmpne	L036
	iconst_0
	goto	L037
L036:
	iconst_1
L037:
	iconst_0
	if_icmpeq	L035
;
; 100 j:=ps[k]
;
	getstatic	Hilbert/ps [I
	iload	6
	iconst_1
	isub
	iaload
	istore	5
;
; 101 ps[k]:=ps[pivotindex]
;
	getstatic	Hilbert/ps [I
	iload	6
	iconst_1
	isub
	getstatic	Hilbert/ps [I
	iload	7
	iconst_1
	isub
	iaload
	iastore
;
; 102 ps[pivotindex]:=j
;
	getstatic	Hilbert/ps [I
	iload	7
	iconst_1
	isub
	iload	5
	iastore
L035:
;
; 105 pivot:=LU[ps[k],k]
;
	aload_2
	getstatic	Hilbert/ps [I
	iload	6
	iconst_1
	isub
	iaload
	iconst_1
	isub
	aaload
	iload	6
	iconst_1
	isub
	faload
	fstore	9
;
; 108 FORi:=k+1TOnDOBEGINmult:=LU[ps[i],k]/pivot;LU[ps[i],k]:=mult;IFmult<>0 ...
;
	iload	6
	iconst_1
	iadd
	istore	4
L038:
	iload_0
	iconst_1
	iadd
	iload	4
	if_icmpeq	L039
;
; 109 mult:=LU[ps[i],k]/pivot
;
	aload_2
	getstatic	Hilbert/ps [I
	iload	4
	iconst_1
	isub
	iaload
	iconst_1
	isub
	aaload
	iload	6
	iconst_1
	isub
	faload
	fload	9
	fdiv
	fstore	12
;
; 110 LU[ps[i],k]:=mult
;
	aload_2
	getstatic	Hilbert/ps [I
	iload	4
	iconst_1
	isub
	iaload
	iconst_1
	isub
	aaload
	iload	6
	iconst_1
	isub
	fload	12
	fastore
;
; 112 IFmult<>0THENBEGINFORj:=k+1TOnDOBEGINLU[ps[i],j]:=LU[ps[i],j]-mult*LU[ ...
;
	fload	12
	iconst_0
	i2f
	fcmpg
	ifne	L042
	iconst_0
	goto	L043
L042:
	iconst_1
L043:
	iconst_0
	if_icmpeq	L041
;
; 115 FORj:=k+1TOnDOBEGINLU[ps[i],j]:=LU[ps[i],j]-mult*LU[ps[k],j];END
;
	iload	6
	iconst_1
	iadd
	istore	5
L044:
	iload_0
	iconst_1
	iadd
	iload	5
	if_icmpeq	L045
;
; 116 LU[ps[i],j]:=LU[ps[i],j]-mult*LU[ps[k],j]
;
	aload_2
	getstatic	Hilbert/ps [I
	iload	4
	iconst_1
	isub
	iaload
	iconst_1
	isub
	aaload
	iload	5
	iconst_1
	isub
	aload_2
	getstatic	Hilbert/ps [I
	iload	4
	iconst_1
	isub
	iaload
	iconst_1
	isub
	aaload
	iload	5
	iconst_1
	isub
	faload
	fload	12
	aload_2
	getstatic	Hilbert/ps [I
	iload	6
	iconst_1
	isub
	iaload
	iconst_1
	isub
	aaload
	iload	5
	iconst_1
	isub
	faload
	fmul
	fsub
	fastore
	iload	5
	iconst_1
	iadd
	istore	5
	goto	L044
L045:
L041:
	iload	4
	iconst_1
	iadd
	istore	4
	goto	L038
L039:
L031:
	iload	6
	iconst_1
	iadd
	istore	6
	goto	L022
L023:
;
; 125 IFLU[ps[n],n]=0THENsingular(SINGULARMATRIX)
;
	aload_2
	getstatic	Hilbert/ps [I
	iload_0
	iconst_1
	isub
	iaload
	iconst_1
	isub
	aaload
	iload_0
	iconst_1
	isub
	faload
	iconst_0
	i2f
	fcmpg
	ifeq	L048
	iconst_0
	goto	L049
L048:
	iconst_1
L049:
	iconst_0
	if_icmpeq	L047
;
; 125 singular(SINGULARMATRIX)
;
	iconst_0
	invokestatic	Hilbert/singular()V
L047:

	return

.limit locals 13
.limit stack 10
.end method

;
; PROCEDURE solve
;
.method private static solve(I[[F[F[F)V

.var 2 is b [F
.var 6 is dot F
.var 4 is i I
.var 5 is j I
.var 1 is lu [[F
.var 0 is n I
.var 3 is x [F
;
; 139 FORi:=1TOnDOBEGINdot:=0;FORj:=1TOi-1DOBEGINdot:=dot+LU[ps[i],j]*x[j];E ...
;
	iconst_1
	istore	4
L050:
	iload_0
	iconst_1
	iadd
	iload	4
	if_icmpeq	L051
;
; 140 dot:=0
;
	iconst_0
	i2f
	fstore	6
;
; 141 FORj:=1TOi-1DOBEGINdot:=dot+LU[ps[i],j]*x[j];END
;
	iconst_1
	istore	5
L052:
	iload	4
	iconst_1
	isub
	iconst_1
	iadd
	iload	5
	if_icmpeq	L053
;
; 142 dot:=dot+LU[ps[i],j]*x[j]
;
	fload	6
	aload_1
	getstatic	Hilbert/ps [I
	iload	4
	iconst_1
	isub
	iaload
	iconst_1
	isub
	aaload
	iload	5
	iconst_1
	isub
	faload
	aload_3
	iload	5
	iconst_1
	isub
	faload
	fmul
	fadd
	fstore	6
	iload	5
	iconst_1
	iadd
	istore	5
	goto	L052
L053:
;
; 144 x[i]:=b[ps[i]]-dot
;
	aload_3
	iload	4
	iconst_1
	isub
	aload_2
	getstatic	Hilbert/ps [I
	iload	4
	iconst_1
	isub
	iaload
	iconst_1
	isub
	faload
	fload	6
	fsub
	fastore
	iload	4
	iconst_1
	iadd
	istore	4
	goto	L050
L051:
;
; 148 FORi:=nDOWNTO1DOBEGINdot:=0;FORj:=i+1TOnDOBEGINdot:=dot+LU[ps[i],j]*x[ ...
;
	iload_0
	istore	4
L054:
	iconst_1
	iconst_1
	isub
	iload	4
	if_icmpeq	L055
;
; 149 dot:=0
;
	iconst_0
	i2f
	fstore	6
;
; 150 FORj:=i+1TOnDOBEGINdot:=dot+LU[ps[i],j]*x[j];END
;
	iload	4
	iconst_1
	iadd
	istore	5
L056:
	iload_0
	iconst_1
	iadd
	iload	5
	if_icmpeq	L057
;
; 151 dot:=dot+LU[ps[i],j]*x[j]
;
	fload	6
	aload_1
	getstatic	Hilbert/ps [I
	iload	4
	iconst_1
	isub
	iaload
	iconst_1
	isub
	aaload
	iload	5
	iconst_1
	isub
	faload
	aload_3
	iload	5
	iconst_1
	isub
	faload
	fmul
	fadd
	fstore	6
	iload	5
	iconst_1
	iadd
	istore	5
	goto	L056
L057:
;
; 153 x[i]:=(x[i]-dot)/LU[ps[i],i]
;
	aload_3
	iload	4
	iconst_1
	isub
	aload_3
	iload	4
	iconst_1
	isub
	faload
	fload	6
	fsub
	aload_1
	getstatic	Hilbert/ps [I
	iload	4
	iconst_1
	isub
	iaload
	iconst_1
	isub
	aaload
	iload	4
	iconst_1
	isub
	faload
	fdiv
	fastore
	iload	4
	iconst_1
	isub
	istore	4
	goto	L054
L055:

	return

.limit locals 7
.limit stack 7
.end method

;
; PROCEDURE invert
;
.method private static invert(I[[F[[F)V

.var 1 is a [[F
.var 2 is ainv [[F
.var 4 is b [F
.var 6 is i I
.var 7 is j I
.var 3 is lu [[F
.var 0 is n I
.var 5 is x [F

	iconst_5
	newarray	float
	astore	4

	iconst_5
	iconst_5
	multianewarray	[[F 2
	astore_3

	iconst_5
	newarray	float
	astore	5
;
; 168 decompose(n,A,LU)
;
	iload_0
	aload_1
	aload_3
	invokestatic	Hilbert/decompose(I)V
;
; 170 FORj:=1TOnDOBEGINFORi:=1TOnDOBEGINIFi=jTHENb[i]:=1ELSEb[i]:=0;END;solv ...
;
	iconst_1
	istore	7
L058:
	iload_0
	iconst_1
	iadd
	iload	7
	if_icmpeq	L059
;
; 171 FORi:=1TOnDOBEGINIFi=jTHENb[i]:=1ELSEb[i]:=0;END
;
	iconst_1
	istore	6
L060:
	iload_0
	iconst_1
	iadd
	iload	6
	if_icmpeq	L061
;
; 172 IFi=jTHENb[i]:=1ELSEb[i]:=0
;
	iload	6
	iload	7
	if_icmpeq	L064
	iconst_0
	goto	L065
L064:
	iconst_1
L065:
	iconst_0
	if_icmpeq	L062
;
; 172 b[i]:=1
;
	aload	4
	iload	6
	iconst_1
	isub
	iconst_1
	i2f
	fastore
	goto	L063
L062:
;
; 173 b[i]:=0
;
	aload	4
	iload	6
	iconst_1
	isub
	iconst_0
	i2f
	fastore
L063:
	iload	6
	iconst_1
	iadd
	istore	6
	goto	L060
L061:
;
; 176 solve(n,LU,b,x)
;
	iload_0
	aload_3
	aload	4
	aload	5
	invokestatic	Hilbert/solve(I)V
;
; 178 FORi:=1TOnDOAinv[i,j]:=x[i]
;
	iconst_1
	istore	6
L066:
	iload_0
	iconst_1
	iadd
	iload	6
	if_icmpeq	L067
;
; 178 Ainv[i,j]:=x[i]
;
	aload_2
	iload	6
	iconst_1
	isub
	aaload
	iload	7
	iconst_1
	isub
	aload	5
	iload	6
	iconst_1
	isub
	faload
	fastore
	iload	6
	iconst_1
	iadd
	istore	6
	goto	L066
L067:
	iload	7
	iconst_1
	iadd
	istore	7
	goto	L058
L059:

	return

.limit locals 8
.limit stack 12
.end method

;
; PROCEDURE multiply
;
.method private static multiply(I[[F[[F[[F)V

.var 1 is a [[F
.var 2 is b [[F
.var 4 is i I
.var 5 is j I
.var 6 is k I
.var 0 is n I
.var 3 is p [[F
.var 7 is sum F
;
; 191 FORi:=1TOnDOBEGINFORj:=1TOnDOBEGINsum:=0.0;FORk:=1TOnDOBEGINsum:=sum+A ...
;
	iconst_1
	istore	4
L068:
	iload_0
	iconst_1
	iadd
	iload	4
	if_icmpeq	L069
;
; 192 FORj:=1TOnDOBEGINsum:=0.0;FORk:=1TOnDOBEGINsum:=sum+A[i,k]*B[k,j];END; ...
;
	iconst_1
	istore	5
L070:
	iload_0
	iconst_1
	iadd
	iload	5
	if_icmpeq	L071
;
; 193 sum:=0.0
;
	fconst_0
	fstore	7
;
; 195 FORk:=1TOnDOBEGINsum:=sum+A[i,k]*B[k,j];END
;
	iconst_1
	istore	6
L072:
	iload_0
	iconst_1
	iadd
	iload	6
	if_icmpeq	L073
;
; 196 sum:=sum+A[i,k]*B[k,j]
;
	fload	7
	aload_1
	iload	4
	iconst_1
	isub
	aaload
	iload	6
	iconst_1
	isub
	faload
	aload_2
	iload	6
	iconst_1
	isub
	aaload
	iload	5
	iconst_1
	isub
	faload
	fmul
	fadd
	fstore	7
	iload	6
	iconst_1
	iadd
	istore	6
	goto	L072
L073:
;
; 199 P[i,j]:=sum
;
	aload_3
	iload	4
	iconst_1
	isub
	aaload
	iload	5
	iconst_1
	isub
	fload	7
	fastore
	iload	5
	iconst_1
	iadd
	istore	5
	goto	L070
L071:
	iload	4
	iconst_1
	iadd
	istore	4
	goto	L068
L069:

	return

.limit locals 8
.limit stack 5
.end method

;
; PROCEDURE printmatrix
;
.method private static printmatrix([[F)V

.var 1 is i I
.var 2 is j I
.var 0 is m [[F
;
; 210 writeln
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	invokevirtual	java/io/PrintStream.println()V
;
; 211 FORi:=1TOnDOBEGINFORj:=1TOnDOwrite(M[i,j]:15:6);writeln;END
;
	iconst_1
	istore_1
L074:
	getstatic	Hilbert/n I
	iconst_1
	iadd
	iload_1
	if_icmpeq	L075
;
; 212 FORj:=1TOnDOwrite(M[i,j]:15:6)
;
	iconst_1
	istore_2
L076:
	getstatic	Hilbert/n I
	iconst_1
	iadd
	iload_2
	if_icmpeq	L077
;
; 212 write(M[i,j]:15:6)
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"%15.6f"
	iconst_1
	anewarray	java/lang/Object
	dup
	iconst_0
	aload_0
	iload_1
	iconst_1
	isub
	aaload
	iload_2
	iconst_1
	isub
	faload
	invokestatic	java/lang/Float/valueOf(F)Ljava/lang/Float;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop
	iload_2
	iconst_1
	iadd
	istore_2
	goto	L076
L077:
;
; 213 writeln
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	invokevirtual	java/io/PrintStream.println()V
	iload_1
	iconst_1
	iadd
	istore_1
	goto	L074
L075:
;
; 215 writeln
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	invokevirtual	java/io/PrintStream.println()V

	return

.limit locals 3
.limit stack 8
.end method

;
; MAIN
;
.method public static main([Ljava/lang/String;)V
.var 0 is args [Ljava/lang/String;
.var 1 is _start Ljava/time/Instant;
.var 2 is _end Ljava/time/Instant;
.var 3 is _elapsed J

	invokestatic	java/time/Instant/now()Ljava/time/Instant;
	astore_1

	iconst_5
	iconst_5
	multianewarray	[[F 2
	putstatic	Hilbert/h [[F

	iconst_5
	iconst_5
	multianewarray	[[F 2
	putstatic	Hilbert/hinv [[F

	iconst_5
	newarray	int
	putstatic	Hilbert/ps [I

	iconst_5
	iconst_5
	multianewarray	[[F 2
	putstatic	Hilbert/z [[F

;
; 219 n:=5
;
	iconst_5
	putstatic	Hilbert/n I
;
; 222 FORi:=1TOnDOBEGINFORj:=1TOnDOBEGINH[i,j]:=1.0/(i+j-1);END;END
;
	iconst_1
	putstatic	Hilbert/i I
L078:
	getstatic	Hilbert/n I
	iconst_1
	iadd
	getstatic	Hilbert/i I
	if_icmpeq	L079
;
; 223 FORj:=1TOnDOBEGINH[i,j]:=1.0/(i+j-1);END
;
	iconst_1
	putstatic	Hilbert/j I
L080:
	getstatic	Hilbert/n I
	iconst_1
	iadd
	getstatic	Hilbert/j I
	if_icmpeq	L081
;
; 224 H[i,j]:=1.0/(i+j-1)
;
	getstatic	Hilbert/h [[F
	getstatic	Hilbert/i I
	iconst_1
	isub
	aaload
	getstatic	Hilbert/j I
	iconst_1
	isub
	fconst_1
	getstatic	Hilbert/i I
	getstatic	Hilbert/j I
	iadd
	iconst_1
	isub
	i2f
	fdiv
	fastore
	getstatic	Hilbert/j I
	iconst_1
	iadd
	putstatic	Hilbert/j I
	goto	L080
L081:
	getstatic	Hilbert/i I
	iconst_1
	iadd
	putstatic	Hilbert/i I
	goto	L078
L079:
;
; 228 writeln
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	invokevirtual	java/io/PrintStream.println()V
;
; 229 writeln('Hilbert matrix:')
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"Hilbert matrix:\n"
	invokevirtual	java/io/PrintStream/print(Ljava/lang/String;)V
;
; 230 printmatrix(H)
;
	getstatic	Hilbert/h [[F
	invokestatic	Hilbert/printmatrix()V
;
; 233 invert(n,H,Hinv)
;
	getstatic	Hilbert/n I
	getstatic	Hilbert/h [[F
	getstatic	Hilbert/hinv [[F
	invokestatic	Hilbert/invert(I)V
;
; 235 writeln('Hilbert matrix inverted:')
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"Hilbert matrix inverted:\n"
	invokevirtual	java/io/PrintStream/print(Ljava/lang/String;)V
;
; 236 printmatrix(Hinv)
;
	getstatic	Hilbert/hinv [[F
	invokestatic	Hilbert/printmatrix()V
;
; 239 multiply(n,H,Hinv,Z)
;
	getstatic	Hilbert/n I
	getstatic	Hilbert/h [[F
	getstatic	Hilbert/hinv [[F
	getstatic	Hilbert/z [[F
	invokestatic	Hilbert/multiply(I)V
;
; 241 writeln('Hilbert matrix multiplied by its inverse:')
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"Hilbert matrix multiplied by its inverse:\n"
	invokevirtual	java/io/PrintStream/print(Ljava/lang/String;)V
;
; 242 printmatrix(Z)
;
	getstatic	Hilbert/z [[F
	invokestatic	Hilbert/printmatrix()V
;
; 245 invert(n,Hinv,H)
;
	getstatic	Hilbert/n I
	getstatic	Hilbert/hinv [[F
	getstatic	Hilbert/h [[F
	invokestatic	Hilbert/invert(I)V
;
; 247 writeln('Inverse matrix inverted:')
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"Inverse matrix inverted:\n"
	invokevirtual	java/io/PrintStream/print(Ljava/lang/String;)V
;
; 248 printmatrix(H)
;
	getstatic	Hilbert/h [[F
	invokestatic	Hilbert/printmatrix()V

	invokestatic	java/time/Instant/now()Ljava/time/Instant;
	astore_2
	aload_1
	aload_2
	invokestatic	java/time/Duration/between(Ljava/time/temporal/Temporal;Ljava/time/temporal/Temporal;)Ljava/time/Duration;
	invokevirtual	java/time/Duration/toMillis()J
	lstore_3
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"\n[%,d milliseconds execution time.]\n"
	iconst_1
	anewarray	java/lang/Object
	dup
	iconst_0
	lload_3
	invokestatic	java/lang/Long/valueOf(J)Ljava/lang/Long;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop

	return

.limit locals 6
.limit stack 7
.end method
