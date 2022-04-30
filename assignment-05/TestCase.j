.class public TestCase
.super java/lang/Object

.field private static _sysin Ljava/util/Scanner;
.field private static ch C
.field private static even I
.field private static i I
.field private static j I
.field private static odd I
.field private static prime I
.field private static str C

;
; Runtime input scanner
;
.method static <clinit>()V

	new	java/util/Scanner
	dup
	getstatic	java/lang/System/in Ljava/io/InputStream;
	invokespecial	java/util/Scanner/<init>(Ljava/io/InputStream;)V
	putstatic	TestCase/_sysin Ljava/util/Scanner;
	return

.limit locals 0
.limit stack 3
.end method

;
; Main class constructor
;
.method public <init>()V
.var 0 is this LTestCase;

	aload_0
	invokespecial	java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
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

;
; 008 i:=3
;
	iconst_3
	putstatic	TestCase/i I
;
; 008 ch:='b'
;
	bipush	98
	putstatic	TestCase/ch C
;
; 009 even:=-990
;
	sipush	990
	ineg
	putstatic	TestCase/even I
;
; 009 odd:=-999
;
	sipush	999
	ineg
	putstatic	TestCase/odd I
;
; 009 prime:=0
;
	iconst_0
	putstatic	TestCase/prime I
;
; 011 CASEi+1OF1:j:=i;-8:j:=8*i;5,7,4:j:=574*i;END
;
	getstatic	TestCase/i I
	iconst_1
	iadd
	lookupswitch
	  -8: L003
	  1: L002
	  4: L004
	  5: L004
	  7: L004
	  default: L001
L002:
;
; 012 j:=i
;
	getstatic	TestCase/i I
	putstatic	TestCase/j I
	goto	L001
L003:
;
; 013 j:=8*i
;
	bipush	8
	getstatic	TestCase/i I
	imul
	putstatic	TestCase/j I
	goto	L001
L004:
;
; 014 j:=574*i
;
	sipush	574
	getstatic	TestCase/i I
	imul
	putstatic	TestCase/j I
	goto	L001
L005:
	goto	L001
L001:
;
; 017 writeln('j = ',j)
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"j = %d\n"
	iconst_1
	anewarray	java/lang/Object
	dup
	iconst_0
	getstatic	TestCase/j I
	invokestatic	java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop
;
; 019 CASEchOF'c','b':str:='p';'a':str:='q'END
;
	getstatic	TestCase/ch C
	lookupswitch
	  97: L008
	  98: L007
	  99: L007
	  default: L006
L007:
;
; 020 str:='p'
;
	bipush	112
	putstatic	TestCase/str C
	goto	L006
L008:
;
; 021 str:='q'
;
	bipush	113
	putstatic	TestCase/str C
	goto	L006
L006:
;
; 024 writeln('str = ''',str,'''')
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"str = '%c'\n"
	iconst_1
	anewarray	java/lang/Object
	dup
	iconst_0
	getstatic	TestCase/str C
	invokestatic	java/lang/Character/valueOf(C)Ljava/lang/Character;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop
;
; 026 FORi:=-5TO15DOBEGINCASEiOF2:prime:=i;-4,-2,0,4,6,8,10,12:even:=i;-3,-1 ...
;
	iconst_5
	ineg
	putstatic	TestCase/i I
L009:
	bipush	15
	iconst_1
	iadd
	getstatic	TestCase/i I
	if_icmpeq	L010
;
; 027 CASEiOF2:prime:=i;-4,-2,0,4,6,8,10,12:even:=i;-3,-1,1,3,5,7,9,11:CASEi ...
;
	getstatic	TestCase/i I
	lookupswitch
	  -4: L013
	  -3: L014
	  -2: L013
	  -1: L014
	  0: L013
	  1: L014
	  2: L012
	  3: L014
	  4: L013
	  5: L014
	  6: L013
	  7: L014
	  8: L013
	  9: L014
	  10: L013
	  11: L014
	  12: L013
	  default: L011
L012:
;
; 028 prime:=i
;
	getstatic	TestCase/i I
	putstatic	TestCase/prime I
	goto	L011
L013:
;
; 029 even:=i
;
	getstatic	TestCase/i I
	putstatic	TestCase/even I
	goto	L011
L014:
;
; 030 CASEiOF-3,-1,1,9:odd:=i;2,3,5,7,11:prime:=i;END
;
	getstatic	TestCase/i I
	lookupswitch
	  -3: L016
	  -1: L016
	  1: L016
	  2: L017
	  3: L017
	  5: L017
	  7: L017
	  9: L016
	  11: L017
	  default: L015
L016:
;
; 031 odd:=i
;
	getstatic	TestCase/i I
	putstatic	TestCase/odd I
	goto	L015
L017:
;
; 032 prime:=i
;
	getstatic	TestCase/i I
	putstatic	TestCase/prime I
	goto	L015
L018:
	goto	L015
L015:
	goto	L011
L011:
;
; 036 writeln('i = ',i,', even = ',even,', odd = ',odd,', prime = ',prime)
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"i = %d, even = %d, odd = %d, prime = %d\n"
	iconst_4
	anewarray	java/lang/Object
	dup
	iconst_0
	getstatic	TestCase/i I
	invokestatic	java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	dup
	iconst_1
	getstatic	TestCase/even I
	invokestatic	java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	dup
	iconst_2
	getstatic	TestCase/odd I
	invokestatic	java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	dup
	iconst_3
	getstatic	TestCase/prime I
	invokestatic	java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop
	getstatic	TestCase/i I
	iconst_1
	iadd
	putstatic	TestCase/i I
	goto	L009
L010:

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
