#include "ia.h"

void IA(int *andou_b,int *andou_c,int *andou_d,int *andou_e, Pessoa *p)
{
	int menor_dist[4]={1000,1000,1000,1000};
	int pessoa_perto[4];
	int dist[4];
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) {
			if(p[i].comp==1) {
				if(i!=j) {
					dist[i]=sqrt((p[j].x-p[i].x)*(p[j].x-p[i].x)+(p[j].y-p[i].y)*(p[j].y-p[i].y));
					if(dist[i]<menor_dist[i]) {
						menor_dist[i]=dist[i];
						pessoa_perto[i]=j;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++) {
		if((p[i].comp==1) && (p[pessoa_perto[i]].time!=p[i].time)) {
			if((p[pessoa_perto[i]].x-p[i].x==0) && (p[pessoa_perto[i]].y-p[i].y>0)) {
				p[i].andou_b = 1;
				p[i].andou_e = 0;
				p[i].andou_d = 0;
				p[i].andou_c = 0;
			} else if((p[pessoa_perto[i]].x-p[i].x==0) && (p[pessoa_perto[i]].y-p[i].y<0)) {
				p[i].andou_c = 1;
				p[i].andou_e = 0;
				p[i].andou_d = 0;
				p[i].andou_b = 0;
			} else if((p[pessoa_perto[i]].x-p[i].x>0) && (p[pessoa_perto[i]].y-p[i].y==0)) {
				p[i].andou_d = 1;
				p[i].andou_c = 0;
				p[i].andou_b = 0;
				p[i].andou_e = 0;
			} else if((p[pessoa_perto[i]].x-p[i].x<0) && (p[pessoa_perto[i]].y-p[i].y==0)) {
				p[i].andou_e = 1;
				p[i].andou_d = 0;
				p[i].andou_c = 0;
				p[i].andou_b = 0;
			} else if((p[pessoa_perto[i]].x-p[i].x>0) && (p[pessoa_perto[i]].y-p[i].y>0)) {
				p[i].andou_b = 1;
				p[i].andou_e = 0;
				p[i].andou_d = 1;
				p[i].andou_c = 0;
			} else if((p[pessoa_perto[i]].x-p[i].x<0) && (p[pessoa_perto[i]].y-p[i].y>0)) {
				p[i].andou_c = 0;
				p[i].andou_e = 1;
				p[i].andou_d = 0;
				p[i].andou_b = 1;
			} else if((p[pessoa_perto[i]].x-p[i].x>0) && (p[pessoa_perto[i]].y-p[i].y<0)) {
				p[i].andou_d = 1;
				p[i].andou_c = 1;
				p[i].andou_b = 0;
				p[i].andou_e = 0;
			} else if((p[pessoa_perto[i]].x-p[i].x<0) && (p[pessoa_perto[i]].y-p[i].y<0)) {
				p[i].andou_e = 1;
				p[i].andou_d = 0;
				p[i].andou_c = 1;
				p[i].andou_b = 0;
			} else {
				//andou_e[i]=0;andou_d[i]=0;andou_c[i]=0;andou_b[i]=0;
			}
		}
	}
}
