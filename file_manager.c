/* ************************************************************************
 *       Filename:  file_manager.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2010��03��08�� 10ʱ28��50��
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/
#include <sys/stat.h>
#include "myinclude.h"
#include "file_manager.h"


static IPMSG_FILE *sendhead = NULL;	//��������
static IPMSG_FILE *recvhead = NULL; //��������

//������(���ջ�������)�����һ���ļ�
//flag : SENDFILE(��������) RECVFILE(��������)
void add_file(IPMSG_FILE temp, int flag)
{
	IPMSG_FILE **phead=NULL, *pf=NULL, *pb=NULL;
	phead = (flag==SENDFILE)?(&sendhead):(&recvhead);
	
	pf = *phead;
	pb = (IPMSG_FILE *)malloc(sizeof(IPMSG_FILE));
	strcpy(pb->name, temp.name);
	strcpy(pb->user, temp.user);
	pb->num = temp.num;
	pb->ltime = temp.ltime;
	pb->size = temp.size;
	pb->pkgnum = temp.pkgnum;
	pb->next = NULL;
		
	if( *phead==NULL )
	{
		*phead = pb;
	}
	else
	{
		while(pf->next != NULL)
		{
			pf = pf->next;
		}
		pf->next = pb;
	}
}

//������(���ջ�������)��ɾ��һ���ļ�
//flag : SENDFILE(��������) RECVFILE(��������)
void del_file(IPMSG_FILE *temp, int flag)
{
	IPMSG_FILE **phead=NULL, *pf=NULL, *pb=NULL;
	phead = (flag==SENDFILE)?&sendhead:&recvhead;
	pb = *phead;
	while(pb!=NULL)
	{
		if( (temp->pkgnum==pb->pkgnum) && (temp->num==pb->num) )
		{
			if(pb==*phead)
				*phead = pb->next;	
			else
				pf->next = pb->next;
			pf=pb->next;
			free(pb);
			return ;
		}
		pf = pb;
		pb = pb->next;
	}
}

//���ݰ���ź��ļ���Ŵӷ��������л�ȡ�ļ�
IPMSG_FILE *getfileinfo(long pkgnum, int filenum)
{
	IPMSG_FILE *p = sendhead;
	while(p!=NULL)
	{
		if( p->pkgnum != pkgnum )
		{
			p = p->next;
			continue;
		}
		if( p->num != filenum )
		{	
			p = p->next;
			continue;
		}
		return p;
	}
	return NULL;
}

//��ȡ�ļ����Դ����fileopt��,�����ļ���Ϣ���뷢��������
int getfileopt(char *fileopt, char *filename, long pkgnum, int num)
{
	int len = 0;
	IPMSG_FILE file;
	struct stat fstat;	
	int ret = stat(filename, &fstat);
	if( ret<0 )
	{	
		IPMSG_OUT_MSG_COLOR(
		printf("No such file:*%s*!\n", filename);
		)
		return 0;
	}
	strcpy(file.name, filename);
	file.num = num;
	file.pkgnum = pkgnum;
	file.size = fstat.st_size;
	add_file(file, SENDFILE);
	len = sprintf(fileopt, "%d:%s:%lx:%lx:%ld\a", \
			file.num, file.name, fstat.st_size, fstat.st_ctime,IPMSG_FILE_REGULAR );
	return len;
}

//�ڽ��������а������(id)�����ļ�
IPMSG_FILE * find_file(int id)
{	
	int i = id;
	IPMSG_FILE *p = recvhead;
	if(p == NULL)
		return NULL;
	for(i=0;i!=id;i++)
	{
		if( p->next == NULL )
		{
			return NULL;
		}
		p = p->next;
	}	
	return p;
}

//��ӡ�����ļ��б�
void file_list(void)
{
	int id = 0;
	IPMSG_FILE *pb = recvhead;
	IPMSG_OUT_MSG_COLOR(
	printf("\rNUM\t\tFILE\t\tSender\n");
	)
	while(pb != NULL)
	{
		IPMSG_OUT_MSG_COLOR(
		printf("%d\t%20s\t%s\n", id++, pb->name, pb->user);
		)
		pb = pb->next;
	}
}
