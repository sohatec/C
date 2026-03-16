#ifndef USER_H
#define USER_H

void createAccount(char *userName, short *dayUser, short *monthUser, short *yearUser, char *email, char *passWord, char *phoneNumber);
void showUserProfile(char *userName, short *dayUser, short *monthUser, short *yearUser, char *email, char *passWord, char *phoneNumber);
void changeEmail(char *email);
void changePassword(char *passWord);

#endif