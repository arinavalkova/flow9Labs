import runtime;
import string;
import ds/tree;

inds1(a : [int], m : int) -> [Pair<int, int>]{
    res = [];
    foldi(a, res, \i, sumi, x ->
        foldi(a, sumi, \j, sumj, y ->
            if(x + y == m){
                concat(sumj, [Pair(i, j)])
            }
            else
                sumj
            )
        )
}

inds2(a : [int], m : int) -> [Pair<int, int>]{
    tree = foldi(a, makeTree(), \i, treei, x ->
            switch(lookupTree(treei, x)){
                Some(ix):{
                    newIx = concat(ix, [i]);
                    setTree(treei, x, newIx);
                }
                None():{
                    setTree(treei, x, [i])
                }
            }
    )

       foldi(a, [], \i, mas, x ->
        switch(lookupTree(tree, m - x)){
            Some(ix):{
                res = foldi(ix, [], \j, sum, y ->
                        concat(sum, [Pair(i, y)])
                    );
                concat(mas, res);
            }
            None():{
                mas;
            }
        }
   )
}

main(){
    a = [1, 2, 3, 1, 2, 3];
    println(inds2(a, 3));
}
