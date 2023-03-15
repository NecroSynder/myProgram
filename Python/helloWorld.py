print("Hello, world!")

def area_of_a_triangel(a, b, c,):
    s = (a + b + c) / 2
    n = (s*(s-a)*(s-b)*(s-c)) ** 0.5
    
    return n


a = float(input('Enter first side: '))
b = float(input('Enter second side: '))
c = float(input('Enter third side: '))

print('The area of the triangle is: %0.2f' %area_of_a_triangel(a, b, c,))


    

