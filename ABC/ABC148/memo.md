# F

- グラフが木なのでどこかの葉に追い詰めるのが最終形態となる
- 葉の特定は，2人とも移動した後に高橋くんが青木くんより先に到達できてその中で最も遠い点となる
- 高橋くんが葉に，青木くんが葉の親の親にいるときにどちらが先に動いても葉の親でゲームが終了する(ここが理解しづらかった)
- 高橋くん，青木くんから見た各点への移動距離はDFS,BFSを使って算出できる(木だからDFSも使える)