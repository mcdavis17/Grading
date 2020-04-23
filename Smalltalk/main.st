Object subclass: People [
	| numPeople students |

	People class >> new [
		| e |

		e := super new.
		e init.
		^e.
	]

	init [
		students := Dictionary new.
		numPeople := 0.
	]

	getData: file [
		| f strings student |
		f := FileStream open: file mode: FileStream read
			ifFail: [
				Transcript show: 'Could not open file.'; cr.
				self addStudent: 0.
				^1.
			].
		f linesDo: [ :line |
			strings := line substrings: Character space.
			( 'pf' sameAs: (strings at: 1) ) ifTrue: [
				student := PF_Student new: (strings at: 2) lname: (strings at: 3) test1: (strings at: 4) test2: (strings at: 5) test3: (strings at: 6).
				self addStudent: student.
			].
			( 'std' sameAs: (strings at: 1) ) ifTrue: [
				student := STD_Student new: (strings at: 2) lname: (strings at: 3) test1: (strings at: 4) test2: (strings at: 5) test3: (strings at: 6).
				self addStudent: student.
			].
		].
		f close.
	]

	addStudent: student [
		students at: numPeople put: student.
		numPeople := numPeople + 1.
	]

	getNumStudents [
		^numPeople.
	]

	returnStudents [
		^students.
	]

	printStudents: average [
		0 to: numPeople-1 do: [ :i |
			Transcript show: (students at: i) printName, Character space asString.
			Transcript show: (students at: i) getGrade, Character space asString.
			Transcript show: ((students at: i) getStatus: average) asString; cr.
			].
	]

	computeAvg [
		| total |
		total := 0.
		students do: [ :st | 
			total := total + (st getStudentAvg).
		].
		^(total / numPeople).
	]

]

ppl := People new.

ppl getData: (Smalltalk getArgv: 1).

(ppl returnStudents at: 0) = 0 ifFalse: [
	average := ppl computeAvg.
	ppl printStudents: average.
]







