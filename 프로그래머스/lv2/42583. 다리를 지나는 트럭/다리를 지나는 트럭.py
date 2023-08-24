from collections import deque

def solution(bridge_length, weight, truck_weights):
    t = 0
    lst = deque([])
    sm = 0
    t_idx = 0
    while t_idx < len(truck_weights):
        t+=1
        for i in range(len(lst)):
            tw, d = lst.popleft()
            d-=1
            if d == 0:
                sm -= tw
            else:
                lst.append((tw, d))
            
        if truck_weights[t_idx] + sm <= weight:
            sm += truck_weights[t_idx]
            lst.append([truck_weights[t_idx], bridge_length])
            t_idx += 1
        
            
    t += bridge_length
        
        
            
    return t