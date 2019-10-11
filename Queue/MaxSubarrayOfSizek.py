import atexit
import io
import sys
from collections import deque
#Contributed by : Nagendra Jha
_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER
@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())
if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases) :
        n,k = map(int,input().strip().split())
        arr = list(map(int,input().strip().split()))
        max_of_subarrays(arr,n,k)
        print()
}
#----------------------------------
def max_of_subarrays(arr,n,k):
    for i in range(n):
        print(max(arr[i:i+k]),end=" ")
        if(i+k>=n):
            break
