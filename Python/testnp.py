import numpy as np

A1 = A2 = A3 = np.array ( [1, 1, 1] )
B1 = B2 = np.array ( [2, 2, 2] )

print ( np.vstack ( ( A1, B1 ) ) )

C = np.vstack ( ( A1, B1 ) )

print ( A.shape, B.shape )

D = np.vstack ( A1, B1, A2, B2, A3 )

E = np.array_split ( D, 3, axis = 1 )

print ( E )
