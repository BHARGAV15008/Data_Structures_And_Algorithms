// Tree should be BST;
// Every root node of tree isw Black;\
// Every red node child must be a black;
// Every nil node must black;
// Every path from the root to the nil node has same number of black nodes;
// Every node is black or red;

/*
-----   Insertion Rule   -----
    * If tree is empty, create new node as root node with color black;
    * If tree is node empty, create new node as leaf node with color red;
    * If color of parent node of the new node is black then exit;
    * If color of parent node of the new node is red then check the parent's sibling (uncle's node) color:
        - If color is black or null then do suitable rotation and recolor it;
        - If color is red then recolor parent and uncle node and also check parent of parent of new node is not root then recolor it and recheck;
*/

/*
-----   Deletion Rule   -----
    * Perform Like deletion in BST;
    -- Case I: If node tobe deleted is red:
        * If node has children nil and color is red simple delete it;
        * If a node has one child then just replce with child and delete it, color should be a same;
        * If a node has two child then we have to replace with inorder succesor or inorder predessesor and color remain same;
        * If a node has two child then we have to replace with inorder succesor or inorder predessesor, but here both have one child then we have to change position with their child and color remain same;
        
    -- Case II: If root is double black:
        * If root is double black and remove it;
    
    -- Case III: If double black has sibling is black & both children are black:
        * remove Blsck instead of double black;
        * Add black to its parent if its parents is red then make it double black;
        * Add black to its parent if its parents is black then make it double black;
        * Make it sibling red;
        * Again double exist then apply some case...;

    -- Case IV: If Double black sibling is red:
        * Make it sibling black and parent red;
        * Rotate parent to Double Black directions;
        * Again same double black problem exist then apply above cases...;
    
    -- Case V: DB's sibling is black, sibling child far from DB is black but near child to DB is red;
        * Swap the color of anger child and their parents;
        * Rotate parent opposite to DB's node;
        * If again DB problem exist the apply case VI;
    
    -- Case VI: DB's sibling is black and far children is red:
        * Swap th color of parent and the sibling;
        * Parent of sibling rotate towards the DB node;
        * Gives black to far child;
*/