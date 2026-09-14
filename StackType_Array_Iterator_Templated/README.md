ok so...

Here's an idea:

1) pop all the elements off the original stack, inspecting them for target value as we go 
2) if target exists, swap with replacement
3) pop this new stack (targets replaced) onto a new tempStack. tempStack is upside-down!
4) pop tempstack elements back onto the original stack – ordering is restored; all targets are replaced!

