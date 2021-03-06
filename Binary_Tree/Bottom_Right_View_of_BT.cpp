// Bottom right View of binary tree
// https://www.geeksforgeeks.org/print-bottom-right-view-of-a-binary-tree/?ref=rp
// Aman Kumar


struct Node
{
	int data ;
	Node *left, *right ;
	
	Node(int key)
	{
		data = key ;
		left = right = NULL ;
	}	
} ;

void traverse( Node *root, int h, int d, map<int,pair<int,int>> &hash )
{
    if( root == NULL )
        return ;
        
    auto iter = hash.find( d ) ;
    
    if( iter == hash.end() )
        hash[d] = make_pair( root -> data, h ) ;
    else
    {
        // Get curr height of that direction index
        int curr_h = (iter -> second).second ;
        
        if( h >= curr_h )
            hash[d] = make_pair( root->data, h) ;
    }
    
    // Traverse on left and right sub tree
    traverse( root -> left, h+1, d-1, hash ) ;
    traverse( root -> right, h+1, d, hash ) ;
}

// Method that returns the bottom view.
vector <int> bottomView(Node *root)
{
   map<int,pair<int,int>> hash ;
   
   // 0 : height of the node
   // 0 : direction index of the node ( left: -1, right: +1 )
   traverse( root, 0, 0, hash ) ;
   
   auto iter = hash.begin() ;
   
   vector<int> ret ;
   
   for( ; iter != hash.end() ; iter++ )
   {
       ret.push_back( (iter -> second).first ) ;
   }
   return ret ;
}
