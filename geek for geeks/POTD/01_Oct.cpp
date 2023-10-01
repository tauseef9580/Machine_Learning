// Question link -- https://practice.geeksforgeeks.org/problems/boundary-traversal-of-matrix-1587115620/1

// Solution 👇👇

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        //approaching like spiral matrix
       vector<int> ans;
        
        int left = 0,right = m-1,top = 0, bottom = n-1;
        int direction = 1; //values of direction :  1-leftToRight
                        //                          2-topToBottom
                        //                          3-rightToLeft
                        //                          4-bottomToTop
        while(left <= right && top <= bottom){
            if(direction == 1){
                for(int i=left; i<=right; i++)
                    ans.push_back(matrix[top][i]);
                
                top++;
                direction = 2;
            }
            
            else if(direction == 2){
                for(int i=top; i<=bottom; i++)
                    ans.push_back(matrix[i][right]);
                
                right--;
                direction = 3;
            }
            
            else if(direction == 3){
                for(int i=right;i>=left;i--)
                   ans.push_back(matrix[bottom][i]);
                   
                direction = 4;
                bottom--;
            }
            
            else if(direction==4)
           {
               for(int i=bottom;i>=top;i--) 
                   ans.push_back(matrix[i][left]);
                   
                
                left++;
                break;
           }
                
        }
        
        return ans;
    }
};
