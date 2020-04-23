Object subclass: Person [
	| firstName lastName |

	Person class >> new: xfname lname: xlname [
		| e |

		e := super new.

		e init: xfname lname: xlname.
		^e.
	]

	init: xfname lname: xlname [
		firstName := xfname.
		lastName := xlname.
	]

	printName [
		^(firstName, ' ', lastName).
	]

]