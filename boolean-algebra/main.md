# 吸收律证明
A+AB
=A*1+AB
=A(1+B)
=A

A+A'B
=A+AB+A'B
=A+(A+A')B
=A+B

A(A+B)
=A+AB
=A

AB+A'C+BC
=AB+A'C+(A+A')BC
=AB+A'C+ABC+A'BC
=AB(1+C)+A'C(1+B)
=AB+A'C

AB+A'C+BCD
=AB+A'C+(A+A')BCD
=AB+A'C+ABCD+A'BCD
=AB(1+CD)+A'C(1+BD)
=AB+A'C

A(AB)'
=A(A'+B')
=0+AB'
=AB'

# 分配律证明
(A+B)(A+C) 
=AA+AB+AC+BC
=A+A(B+C)+BC
=A*1+A(B+C)+BC
=A(1+B+C)+BC
=A+BC

# 布尔代数化简
A(B'CD)'+AB'CD
=A((B'CD)'+B'CD)
=A*1=A

AB'+ACD+A'B'+A'CD
=A(B'+CD)+A'(B'+CD)
=(A+A')(B'+CD)
=B'+CD

A'BC'+AC'+B'C'
=A'BC'+(A+B')C'
=(A'B)C'+(A'B)'C'
=(A'B+(A'B)')C'
=C'

BC'D+BCD'+BC'D'+BCD
=BD(C'+C)+BD'(C+C')
=(BD+BD')(C+C')
=B(D+D')
=B
