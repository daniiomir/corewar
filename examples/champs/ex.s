.name "zork"
.comment "just a basic living prog"
		
l2:	st	r1,2
	ld  %278,r3	
	sti	r1,%:live,%0
	and	r1,%0,r1
live:	live	%1
	zjmp	%:live
