//자바 코딩퀴즈ㅜㅜ
	public class Q4_Queue {
		private Q4_Queue link;
		private Q4_Queue rear;
		private Q4_Queue front;
		private String data;
		static int size;
		
		public Q4_Queue() {
			front= null;
			rear = null;
			link = null;
			data = null;
			}
		
		public Q4_Queue(String newdata, Q4_Queue linkValue) {
			data = newdata;
			link = linkValue;
		}
		
		public void Push(String str) {
			rear = new Q4_Queue(str,rear);
			size++;
		}
		
		public String Pop() {
			Q4_Queue cur =rear;
			String result;
			
			for(int i=0;i<size;i++) {
				front = cur; //front는 cur을 가리키고
				cur = cur.link; //cur은 node수만큼 끝까지 이동한다.
			}
			result = front.data;
			size--; //node 수 하나 줄이기 
			return result;
		
		}
		
		public void showData() {
			Q4_Queue cur = rear;
			
			for(int i=0;i<size;i++) {
			System.out.print(cur.data+" ");
			cur=cur.link;
			}
			
			System.out.println();
		}
			
	}



