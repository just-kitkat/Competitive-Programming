
struct node{
    int s,e,mn,mx;
    ii sum; // {cnt,val}
    bool lset;
    int add_val,set_val;
    node *l,*r;
    node(int ss,int ee):s(ss),e(ee),mn(0),mx(0),sum({0,0}),lset(0),add_val(0),set_val(0),l(NULL),r(NULL){
        return;
    }
    void create_children(){
        if(s==e)return;
        if(l!=NULL)return;
        int m=(s+e)>>1;
        l=new node(s,m);
        r=new node(m+1,e);
    }
    void self_set(int v){
        lset=1;
        mn=mx=set_val=v;
        sum=v*(e-s+1);
        add_val=0;
    }
    void lazy_propagate(){
        if(s==e)return;
        if(lset){
            l->self_set(set_val),r->self_set(set_val);
            lset=set_val=0;
        }
    }
    void combine(){
        if(l==NULL)return;
        sum=l->sum+r->sum;
        mn=min(l->mn,r->mn);
        mx=max(l->mx,r->mx);
    }
    void set(int x, int y, int v){
        if(s==x and e==y){self_set(v);return;}
        int m=(s+e)>>1;
        create_children();lazy_propagate();
        if(x<=m)l->set(x,min(y,m),v);
        if(y>m)r->set(max(x,m+1),y,v);
        combine();
    }
    int range_sum(int x,int y){
        if(s==x and e==y)return sum;
        if(l==NULL or lset)return (sum/(e-s+1))*(y-x+1);
        int m=(s+e)>>1;
        lazy_propagate();
        if(y<=m)return l->range_sum(x,y);
        if(x>m)return r->range_sum(x,y);
        return l->range_sum(x,m)+r->range_sum(m+1,y);
    }
    ~node(){
        if(l!=NULL)delete l;
        if(r!=NULL)delete r;
    }
};