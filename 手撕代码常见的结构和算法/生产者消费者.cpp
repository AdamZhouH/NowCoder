#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

typedef struct msg{
	struct msg *next;
	int num;
}msg_t;

pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t has_p=PTHREAD_COND_INITIALIZER;
msg_t *head;

//生产者函数的实现
void *producer(void *p){
	msg_t *mp;
	while(1){
		mp=malloc(sizeof(msg_t));
		mp->num=rand()%1000+1;
		printf("producer %d\n",mp->num);
		//操作全局变量之前加锁
		pthread_mutex_lock(&lock);
		mp->next=head;
		head=mp;
		pthread_mutex_unlock(&lock);
		//给等待条件的消费者发送信号
		pthread_cond_signal(&has_p);
		sleep(rand()%5);
	}
}
//消费者函数的实现
void *consumer(void *mp){
	msg_t *p;
	while(1){
		pthread_mutex_lock(&lock);
		//如果没有生产，就一直等着生产
		while(head==NULL){
			pthread_cond_wait(&has_p,&lock);
		}
		//消费结构体变量
		p=head;
		head=p->next;
		//解除mutex锁
		pthread_mutex_unlock(&lock);
		printf("consumer %d\n",p->num);
		free(p);
		sleep(rand()%5);
	}
}

// 主线程
int main(void){
	pthread_t pid;//生产者的tid
	pthread_t cid;//消费者的tid

	srand(time(NULL));
	//创建两个线程
	pthread_create(&pid,NULL,producer,NULL);
	pthread_create(&cid,NULL,consumer,NULL);
	pthread_join(pid,NULL);
	pthread_join(cid,NULL);

	return 0;
}