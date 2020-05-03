#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

#define int long long 

int32_t main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,days;
	    cin>>n>>days;
	     vector<pair<int , int >> sadnessRating;
	    int start[n] , lectures[n] , sadness[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>start[i]>>lectures[i]>>sadness[i];
	        start[i]--;
	    }
	    for(int i=0;i<n;i++)
	    {
	        sadnessRating.push_back(make_pair(sadness[i] , i));
	    }
	    sort(sadnessRating.rbegin() , sadnessRating.rend());
	    
	    set<int> days_where_lecture_can_be_taken ; 
	    
	    //starting all days are free
	    
	    for(int i= 0 ;i<days;i++)
	        days_where_lecture_can_be_taken.insert(i);
	        
	        
	    int lectures_taken_by_teacher[n];
	    
	    //initially no one takes lectures
	    for(int i=0;i<n;i++)
	        lectures_taken_by_teacher[i] = 0;
	    for(auto it : sadnessRating)
	    {
	        int lecture = lectures[it.second];
	        
	        for(int i=0;i < lecture ; i++ )
	        {
	            //in set lower_bound returns greater than or equal to paased value which is present in set
	            //if no greater than or equal to value is present it returns iterator pointing to end
	            auto it1 = days_where_lecture_can_be_taken.lower_bound(start[it.second]);
	            if(it1==days_where_lecture_can_be_taken.end())
	            {
	               // if(days_where_lecture_can_be_taken.find(start[i]) != days_where_lecture_can_be_taken.end())
	                 //   lectures_taken_by_teacher[it.second]++;
	                break;
	            }     
	            else
	            {
	                lectures_taken_by_teacher[it.second]++;
	                // one lecture has been allocated to the day
	                days_where_lecture_can_be_taken.erase(it1);
	            }
	        }
	    }
	    int final_sadness_ans=0 ;
	    for(int i=0;i<n;i++)
	    {
	        final_sadness_ans+= (lectures[i] - lectures_taken_by_teacher[i])*sadness[i];  
	    }
	    cout<<final_sadness_ans<<endl;
	}
    

	return 0;
}