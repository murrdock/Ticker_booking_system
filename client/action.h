
#ifndef _action_h
#define _action_h


#define PORT 12385
#define PASS_LENGTH 20

int irctc(int sock);
int menu2(int sock, int type);
int do_admin_action(int sock, int action);
int do_action(int sock, int opt);
void view_booking(int sock);

#endif
