class Array
{
	private:
		int *a,n;
		int anyWay (Array &B)
		{
				if (n!=B.n)
			{
				return 0;
			}
			for (int i=0; i < n; i++)
			{
				if (a[i]!=B.a[i])
				{
					return 0;
				}
			}
			return 1;
		}
		void deleteElement (int l)
		{
			int *b, i;
			b=new int [n];
			for (int i=0; i<n;i++)
			{
				b[i]=a[i];
			}
			delete [] a;
			n-=1;
			a=new int [n];
			for (i=0; i<l; i++)
			{
				a[i]=b[i];
			}
			int j=l+1;
			for (; i<n && j<n+1; i++, j++)
			{
				a[i]=b[j];
			}
			delete [] b;
		}
	public:
			Array (int = 1);
			Array (int *, int );
			Array (Array &);
			~Array ();
			int & operator [] (int );
			void Enter ();
			void Print ();
			Array & operator = (Array &);
			int operator == ( Array &);
			int operator != ( Array &);
			int getDimension ();
			int Order ();
			int Find (int);
			void addToPosition (int, int);
			Array & operator += (Array &);
			Array operator + (Array &);
			Array & operator -= (int);
			Array & operator - (int);
			void deleteToPosition (int);
			Array & operator << (int);
			Array & operator >> (int);
			void Formation (int);
};
