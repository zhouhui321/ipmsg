/* ************************************************************************
 *       Filename:  user_manager.h
 *    Description:  
 *        Version:  1.0
 *        Created:  2010��03��08�� 10ʱ28��50��
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/

#ifndef _LIST_H_
#define _LIST_H_

//�û���Ϣ�ṹ��
typedef struct userlist
{
	char name[20];	//�û���
	char host[20];	//������
	int s_addr;		//IP��ַ(32λ�����ֽ���)
	struct userlist *next;
}IPMSG_USER;

//���û��б������һ���û��ڵ�
void add_user(IPMSG_USER temp);
//���û��б���ɾ��һ���û��ڵ�
void del_user(IPMSG_USER temp);
//�����û�������IP��ַ
int get_addr_by_name(char *name);
//��ӡ�û��б�
void list(void);
//void free_link(void);

#endif	//_LIST_H_
