/*
Answer:
    Function Hiding:
        If a derived class declares a function with the same name as one class
        (even with different parameters), it hides all base class versions of 
        that name.
    Why error?
        d.show() looks only in Derived, but Derived has only show(int).
        So no match for show().
*/