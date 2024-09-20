/*	Raj Kanani
	MT2024074
	Write a program to display the environmental variable of the user (use environ).
*/
#include<stdio.h>
#include<stdlib.h>
extern char **environ;
int main()
{
	char **e = environ;
	while(*e){
		printf("%s\n", *e);
		e++;
	}
	return 0;
}

/*	OUTPUT :
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_15$ ./prog_15
	SHELL=/bin/bash
	SESSION_MANAGER=local/kanani-raj-HP-Laptop-15s-du1xxx:@/tmp/.ICE-unix/1618,unix/kanani-raj-HP-Laptop-15s-du1xxx:/tmp/.ICE-unix/1618
	QT_ACCESSIBILITY=1
	COLORTERM=truecolor
	XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
	SSH_AGENT_LAUNCHER=openssh
	XDG_MENU_PREFIX=gnome-
	GNOME_DESKTOP_SESSION_ID=this-is-deprecated
	GNOME_SHELL_SESSION_MODE=ubuntu
	SSH_AUTH_SOCK=/run/user/1000/keyring/ssh
	XMODIFIERS=@im=ibus
	DESKTOP_SESSION=ubuntu
	GTK_MODULES=gail:atk-bridge
	PWD=/home/kanani-raj/Practicals/Practical_15
	LOGNAME=kanani-raj
	XDG_SESSION_DESKTOP=ubuntu
	XDG_SESSION_TYPE=wayland
	SYSTEMD_EXEC_PID=1647
	XAUTHORITY=/run/user/1000/.mutter-Xwaylandauth.ADEBT2
	HOME=/home/kanani-raj
	USERNAME=kanani-raj
	IM_CONFIG_PHASE=1
	LANG=en_US.UTF-8

*/
