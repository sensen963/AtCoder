# C

- bit全探索
- 早くかけるように頑張る

# D

- 各数の各bitごとに分解して考える
- 桁上りがないため上記のように考えても良い
- k桁めを考えると(0,1)の組み合わせのときに答えに加算される
- したがって$\sum_k(k桁目が0の数)*(k桁目が1の数)*2^(k-1)$

# E

- 到達可能性でDP
- 数字とマス目が100程度なので偏りの最大値は高々100*100オーダー
- なので80*80 * 100のDpで済む
- あるマスから次のマスに進む際に到達可能であるかどうかのboolをでんぱしていく
- vector<vector<set<int>>>を考えたが取り出しにlogオーダーかかるのでTLEした