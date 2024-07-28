pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
	// Write your code here.
	int first=-1;
	int second=-1;
	int s=0;
	int e=n-1;
	int mid=s+(e-s)/2;
	while(s<=e){
          if (arr[mid] <= x) {
			  first=arr[mid];
			  s=mid+1;
          }else{
			  e=mid-1;
		  }
		  mid=s+(e-s)/2;
        }
	int ss=0;
	int ee=n-1;
	int m=ss+(ee-ss)/2;
	while(ss<=ee){
		if(arr[m]>=x){
			second=arr[m];
			ee=m-1;
		}else{
			ss=m+1;
		}
		m=ss+(ee-ss)/2;
	}
	return make_pair(first,second);
	
}
