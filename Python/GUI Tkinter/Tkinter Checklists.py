from tkinter import *

root=Tk()

c = Checkbutton(root, text= "Python")

c.pack()

c1 = Checkbutton(root, text= "C++")

c1.pack()

c2 = Checkbutton(root, text= "C")

c2.pack()

root.geometry("500x600")

root.mainloop()
