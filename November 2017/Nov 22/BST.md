#Cây nhị phân
	##Thứ tự giữa:

    				8
				   / \
				  7   2
				 / \  | \
				6  1  3  5

	##Thủ tục:
    ```
    	visit ()
		{
			if (u == null) return;
			visit (u.l);
			output (u);
			visit (u.r);
		}

		visit (root);
    ```
		output: 6 7 1 8 3 2 5

	##Chèn: Muốn chèn một phần tử vào trước phần tử 8: tạo thêm nút con trái cho nút 3
	```			    8
				   / \
				  7   2
				 / \  | \
				6  1  3  5
					  |
					  4
		output = 6 7 1 8 4 3 2 5
    ```

	##Biểu diễn:
    ``` 
        struct node;
        typedef node* pnode
        struct node
        {
            int value;
            int size;
            pnode p, l, r;
        };
        
        pnode root, nil;
        void make_nil ()
        {
            nil = new node;
            *nil = {0, 0, nil, nil, nil};
        }
    ```


    ##Các thao tác
    ``` 
        // Đặt nút y làm con x
        void setlink (pnode x, pnode y, bool right)
        {
            y -> p = x;
            right ? x -> r = y : x -> l = y;
        }
        // Dựng cây biểu diễn 1, 2, 3,..., n
        void init ()
        {
            root = nil;
            for (i = 1 to n)
            {
                pnode x = new node {i, i, nil, root, nil}
                root -> p = x;
                root = x;
            }
        }
        // In ra cây
        void print ()
        {
            if (x == nil) return
            print (x -> l);
            cout << x -> value;
            print (x -> r);
        }
        inline void update (pnode x)
        {
            x -> size = x -> l -> size + x -> r -> size + 1;
        }
        // tìm nút thứ i trong cây gốc T
        pnode find (pnode t, int i)
        {
            while (true)
            {
                int lsize = t -> l -> size;
                if (lsize + 1 == i) return T;
                if (i <= lsize) t = t -> l;
                else i -= lsize + 1, t = t -> r;
            }
            return t;
        }
    ```

    ## Cân bằng cây:
    Thao tác quay:
        z                                        z
         \                                        \
          y               uptree                   x
         / \              ------>                 / \
        x   c                                    A   y
       / \                                          / \
      A   B                                        B   C
    Inorder của cả 2 cây vẫn là ÃxByC

      z                                           z
       \                                           \
        y                 uptree                    x
       / \                ------>                  / \
      A   x                                       y   C 
         / \                                     / \
        B   C                                   A   B
    Inorder của cả 2 cây vẫn là ÃxByC

    ```
    void uptree (pnode x)
    {
        pnode y = x -> p, z = y -> p;
        if (x == y -> l)
        {
            setlink (y, x -> R, false);
            setlink (x, y, true);
        }
        else
        {
            setlink (y, x -> L, true);
            setlink (x, y, false);
        }
        setlink (z, x, z -> R == y);
        update (y);
        update (z);
    }

    void splay (pnode x)
    {
        while (x -> p != nil) uptree (x);
        // Đẩy x lên làm gốc
    }

    Cây T, chỉ số i
    Tách thành 2 cây a và b
    A chưa các phần tử chỉ số 1 -> i B chứa các phần từ từ i + 1 đến hết

    void split (pnode t, int i, pnode &a, pnode &b)
    {
        if (i == 0) 
        {
            a = nil;
            b = t;
            return;
        }
        pnode  x = find (t, i);
        splay (x);
        a = x, b = x -> r;
        a -> r = nil;
        b -> p = nil;
        update (a);
    }

    pnode join (pnode a, pnode b)
    {
        while (a -> r != nil) a = a -> r;
        splay  (a);
        setlink (a, b, true);
        update (a);
    }
```