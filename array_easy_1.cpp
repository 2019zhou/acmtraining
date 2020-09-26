// ms prep: kth largest element

// 构造最小堆，堆的大小为k, 每次add 之后返回堆头








//Java
class KthLargest{
	private PriorityQueue<Integer> pq;
	private int k;
	public KthLargest(int k, int[] nums){
		this.k = k;
		this.pq = new PriorityQueue<>();
		for(int i:nums){
			pq.add(i);
			maintainKLength();
		}
	}
	private void maintainKLength(){
		if(pd.size > k){
			pd.poll();
		}
	}

	public int add(int val){
		pd.add(val);
		maintainKLength();
		return Optional.ofNullable(pq.peek()).orElse(-1);
	}
}