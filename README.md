# adjacency

 + UserID { add a user with the UserID to the graph. If a user with the id UserID already
exists, the graph remains unchanged and the program outputs the message \User
UserID already has an account[newline]". If the add is successful, the program outputs
the message \User UserID has joined the social network[newline]".

 - UserID { remove a user with the UserID from the graph. If a user with the id UserID
does not exist, the graph remains unchanged and the program outputs the message
\User UserID does not have an account[newline]". If the remove is successful, the program
outputs the message \User UserID has deleted their account[newline]".


 follow UserID1 UserID2 { let UserID1 follow UserID2. If UserID1 or UserID2 does
not exist, the command has no eect on the graph and outputs a message similar to
the - (remove) command above. Note that for consistency of output, given two user-ids,
the program only checks the second id if the rst id exists in the graph. If userID1
is the same as userID2, the graph remains unchanged and the program outputs the
message \Cannot follow yourself[newline]". If userID1 is already following userID2,
the graph remains unchanged and the program outputs the message \User UserID1 is
already following UserID2[newline]". If the command is successful, the program outputs
the message \User UserID1 is now following UserID2[newline]".


 unfollow UserID1 UserID2 { let UserID1 unfollow UserID2. See above for what to
output if UserID1 or UserID2 are not in the graph. If userID1 is the same as userID2,
the graph remains unchanged and the program outputs the message \Cannot follow yourself
therefore cannot unfollow yourself[newline]". If UserID1 is not following UserID2,
the graph remains unchanged and the program outputs the message \User UserID1 was
not following UserID2[newline]". If the command is successful, the program outputs the
message \User UserID1 is no longer following UserID2[newline]".


 print UserID { print the users UserID is following. If the UserID is not in the graph, a
message similar to the one in the - (remove) command is output. If UserID is not following
anyone, then the program outputs \User UserID is following no one[newline]". Otherwise,
the program outputs the message \User UserID is following UserList[newline]",
where UserList is a single user id if UserID is only following one user and a comma
separated list of ids otherwise. For consistency of output, the follow list is output in the
order UserID began to follow users.


 printall { convenience command which calls print UserID for all users in the social
network in the order in which they joined the network.


 list UserID n { prints the number of unique users reachable from UserID through up
to n levels of follow relationships. For example, if Jim (UserID 1) follows Tom and Tom
follows David, then David is reachable from Jim via two levels of relationships. Note
that if Jim also follows Alice who follows David, then list 1 2 would only count David
once (even though there are two paths to David). If UserID is not in the graph, a message
similar to the one in the - (remove) command is output. You may assume that n is
greater than 0.


 include filename { reads the le filename and executes the commands contained
therein. There is no restriction on what command might occur in the specied le.


 quit { quits the program.
