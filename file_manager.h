/* ************************************************************************
 *       Filename:  file_manager.h
 *    Description:  
 *        Version:  1.0
 *        Created:  2010��03��08�� 10ʱ28��50��
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/
#ifndef _FILE_H_
#define _FILE_H_

#define SENDFILE	0
#define RECVFILE	1

//�ļ���Ϣ�ṹ��
typedef struct filelist
{
	char name[50];
	int num;
	long pkgnum;
	long size;
	long ltime;
	char user[10];	
	struct filelist *next;
}IPMSG_FILE;

//������(���ջ�������)�����һ���ļ�
//flag : SENDFILE(��������) RECVFILE(��������)
void add_file(IPMSG_FILE temp, int flag);
//������(���ջ�������)��ɾ��һ���ļ�
//flag : SENDFILE(��������) RECVFILE(��������)
void del_file(IPMSG_FILE *temp, int flag);
//�ڽ��������а������(id)�����ļ�
IPMSG_FILE * find_file(int id);
//���ݰ���ź��ļ���Ŵӷ��������л�ȡ�ļ�
IPMSG_FILE *getfileinfo(long pkgnum, int filenum);
//��ȡ�ļ����Դ����fileopt��,�����ļ���Ϣ���뷢��������
int getfileopt(char *fileopt, char *filename, long pkgnum, int num);
//��ӡ�����ļ�����
void file_list(void);

//void free_link(void);

#endif	//_FILE_H_
