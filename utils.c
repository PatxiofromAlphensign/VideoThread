#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include  <utils.h>


int *get_pointer_array(int arr[]) {
	int *const_pointer_store = (int*)malloc(sizeof(arr)*sizeof(int));
	for(int i=1;;i++) {
		const_pointer_store[i] = *(int*)((void*)&arr + sizeof(int)*i);
		if(arr[i]==NULL) break;
	}
	return const_pointer_store;
}

struct stream *_covert(struct vfstream *sm, char input[]){ 
	struct stream *stm = (struct stream*)malloc((sizeof(struct stream)));
	int i=0;
	do {
		sm->stm.size = i;
		//sm->stm = (struct stream*)malloc(sizeof(sm->stm));
		stm[i] = sm->stm;
		i++;
	} while(i<2);
	
	return stm;
}

void arrcpy(struct vfstream *stm1,struct vfstream *stm2)  {
	for(int i=0;i<2;i++) stm2[i] = stm1[i];
}

void pointer_ref(struct vfstream *stm, int arr[]) {
	struct vfstream *vfs = (struct vfstream*)(void*)(int*)&stm;
	arrcpy(vfs,stm);
	int i=0;
	do {
		vfs[i];
		i++;
		printf("%s ", "fuck ");
	} while(&vfs[i]!=NULL);
}

int main() {
	int arr[] = {1,2,4,5,1,1};
	struct vfstream stream;
	struct stream *ss = _covert(&stream, "test.mp4");
	int *got_arr = get_pointer_array(arr);

	pointer_ref(&stream, arr);

	for(int i=1;got_arr[i]!=NULL;i++) printf("%ls", &got_arr[i]);
	return 0;
}
