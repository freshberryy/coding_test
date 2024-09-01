else if(visited[next] == visited[now] + 1){
                    cnt[next] += cnt[now];
                }