Person subclass: PF_Student [
	| exam1 exam2 exam3 |

	PF_Student class >> new: xfname lname: xlname test1: one test2: two test3: three [
		| e |

		e := super new: xfname lname: xlname.
		e init: one test2: two test3: three.
		^e.
	]

	init: one test2: two test3: three [
		exam1 := one.
		exam2 := two.
		exam3 := three.
	]

	getStudentAvg [
		^( (0.25*exam1 asNumber) + (0.25*exam2 asNumber) + (0.5*exam3 asNumber) ).
	]

	getGrade [
		(self getStudentAvg) >= 60
			ifTrue: [ ^('P'). ].
		^('F').
	]

	getStatus: threshold [
		(self getStudentAvg) = threshold asNumber
			ifTrue: [ ^('Equal'). ].
		(self getStudentAvg) < threshold asNumber
			ifTrue: [ ^('Below'). ].
		^('Above').
	]
]