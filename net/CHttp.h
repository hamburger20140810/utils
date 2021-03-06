#ifndef _CHttp_h_
#define _CHttp_h_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <pthread.h>
#include <sys/wait.h>
#include <locale.h>
#include <signal.h>

#include <unistd.h>
#include <dirent.h>
#include <errno.h>

#include <sys/statvfs.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <stdarg.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/if.h> 
#include <sys/socket.h> 
#include <sys/ioctl.h> 
#include <netinet/in.h> 
#include <poll.h>


class CHttp
{
public:
	CHttp(void);
	~CHttp(void);
	int m_socket;
	int m_nStatusCode;	//
	char m_sDomain[256];
	char m_sPath[256];
	long m_nIP;
	int  m_nPort;  
    

	int Connect(char *sIP,int port);
	int Connect(long  nIP,int port);
	int Connect();
	int Send(unsigned char *Buf,int len);
	int Recv(unsigned char *Buf,int len,int ms=8000);
	int Post(char *url,unsigned char *Buf,int len);
	int Get(unsigned char *Buf,int len);
	int Status();
	int Close();

	long Domain2IP(char *sDomain);
	int setnonblocking(int sock);

	int SetURL(char *URL);
	int PostData(unsigned char *Buf,int len);
	int SendData(const char *m_TeleNum,char *mPushMsg);
	int RecvData(char *Buf,int len);
	int RecvData2(char *Buf,int len);
};
#endif
