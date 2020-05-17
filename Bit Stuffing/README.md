In this bit stuffing implemetation, bits are stuffed in 2 ways.

1. If there are more than 4 consecutive 1s in the input, the sequence of flag bits (01111110) is stuffed after the fourth "1"
2. The flag bits are stuffed before the leftmost and after the rightmost bit before transmission and removed at the receiver's end

In this case, since the program is being run on one computer, the sender and receiver are technically the same, so the program is meant to illustrate how bit stuffing would work in an actual scenario.
