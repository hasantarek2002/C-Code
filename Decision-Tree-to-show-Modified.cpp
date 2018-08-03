#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define bug printf("TRUST\n")
const int cc = 10;
int N;

struct data{
    double col[cc];
};

struct condition{
    int ind = 0;
    double value = 0;
    bool decision = 0;
    int ans = 0;
    int leftChild, rightChild;

}con[1000000];

vector <data> v;
vector <data> v1;
vector <string> columns;

double average[cc];

void print(int node){
    cout << "node " << node << " ans " << con[node].ans << " dc " << con[node].decision << " ind " << con[node].ind << " val " << con[node].value << endl;
}
void printDouble(double d){
    cout << fixed << setprecision(6) << d << endl;
}

double getAvg(vector <data> &v, int ind, int l, int r){
    double avg = 0.0;
    for(int i = l; i <= r; i++){
        avg += v[i].col[ind];
    }
    return (double) avg / (r - l + 1) * 1.0;
}


double calculateEntropy(LL cnt, LL total){
    if(cnt == 0 or total == 0)return 0.0;
    return (double) -1.0 * ((cnt * 1.0)/(total * 1.0)) * log2((cnt * 1.0)/(total * 1.0));
}

int ss;
double featureEntropy(double val, int index, int l, int r){
  //  cout << "Feature\n";
   // cout << index << endl;
    //printDouble(val);

    map <int, int> lessOrEqual, greaterThan;
    int small = 0, large = 0;
    for(int i = l; i <= r; i++){
        if(v[i].col[index] <= val){
            small++;
            lessOrEqual[v[i].col[N - 1]]++;
        }
        else {
            large++;
            greaterThan[v[i].col[N - 1]]++;
        }
    }

    double entropyPart1 = 0.0, entropyPart2 = 0.0;
    for(auto it = lessOrEqual.begin(); it != lessOrEqual.end(); it++){
      //  cout << it -> first << " small " << it -> second << endl;
        entropyPart1 += (double) calculateEntropy(it -> second, small);
    }
    entropyPart1 *= small;
    entropyPart1 /= v.size();

    for(auto it = greaterThan.begin(); it != greaterThan.end(); it++){
        //cout << it -> first << " great " << it -> second << endl;
        entropyPart2 += (double) calculateEntropy(it -> second, large);
    }
    entropyPart2 *= large;
    entropyPart2 /= v.size();
 //   cout << "Small " << small << endl;
    ss = small;
   // cout << "Entropy\n";
   // printDouble(entropyPart1);
    //printDouble(entropyPart2);

    return entropyPart1 + entropyPart2;
}

void restructure(int l, int r, int index, double val){

    vector <data> v1, v2;

    for(int i = l; i <= r; i++){
        if(v[i].col[index] <= val){
            v1.push_back(v[i]);
        }
        else v2.push_back(v[i]);
    }

    int i = l, j = 0;
    for(; j < v1.size(); i++){
        v[i] = v1[j++];
    }
    j = 0;
    for(;j < v2.size(); i++){
        v[i] = v2[j++];
    }
    v1.clear();
    v2.clear();
}

int maxi = -10;
int nodeCount = 0;
int H = 0;
void recursion(int node, int l, int r, double *avg, int height){
 //   cout << "NODE::: " << node << " L " << l << " R " << r << " par " << par << endl;
    double prev = 0.0;

    maxi = max(maxi, node);
    H = max(height, H);
    //nodeCount++;
    map <int, int> decision;
    for(int i = l; i <= r; i++){
        decision[(int)v[i].col[N - 1]]++;
    }

    int range = r - l + 1;
    for(auto it = decision.begin(); it != decision.end(); it++){
        prev += calculateEntropy(it -> second, range);
    }
    if(prev <= 0.00000001){
        con[node].decision = true;
        con[node].ans = v[l].col[N - 1];
        con[node].value = 0.0;
        return;
    }

    pair <int, int> p1, p2;
    double mn = 1e17;
    int ans = -1;
    int sz = -1;
    for(int i = 0; i < N - 1; i++){
        double temp = featureEntropy(average[i], i, l, r);

        if(mn > temp){
            ans = i;
            sz = ss;
            mn = temp;
        }

    }

    con[node].decision = false;
    con[node].ind = ans;
    con[node].value = average[ans];
    nodeCount++;
    con[node].leftChild = nodeCount;
    nodeCount++;

    con[node].rightChild = nodeCount;
    //cout << con[node].leftChild << " xxx " << con[node].rightChild << endl;
    restructure(l, r, ans, average[ans]);
    double temp[N];
    for(int i = 0; i < N - 1; i++){
        temp[i] = average[i];
        average[i] = getAvg(v, i, l, l + sz - 1);

    }

    recursion(con[node].leftChild, l, l + sz - 1, average, height + 1);
    for(int i = 0; i < N - 1; i++){
        average[i] = getAvg(v, i, l + sz, r);
    }
    recursion(con[node].rightChild, l + sz, r, average, height + 1);
    for(int i = 0; i < N - 1; i++){
        average[i] = temp[i];
    }
}

int query(int node, data d){
    if(con[node].decision)
        return con[node].ans;
    if(d.col[con[node].ind] <= con[node].value){
        return query(con[node].leftChild, d);
    }
    else return query(con[node].rightChild, d);
}

void clearString(string &s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ',')s[i] = ' ';
    }
}

void setMin(double *mx, int sz){
    for(int i = 0; i < sz; i++){
        mx[i] = 0.0;
    }
}

int classes = 0;
void readFile(){
   // ifstream f ("Cryotherapy.csv");
    srand(time(NULL));
    ifstream f ("bank.txt");
    string s;
    getline(f, s);
    clearString(s);
    istringstream iss(s);
    while(iss >> s){
        columns.push_back(s);
    }
    N = columns.size();
    double total[N];
    setMin(total, N);
    map <int, int> deci, cnt;

    while(getline(f, s)){
        clearString(s);
        istringstream iss(s);
        int cnt = 0;
        double d;
        data dd;
        while(iss >> d){
          //  total[cnt] += d;
            dd.col[cnt++] = d;

        }
        deci[ (int)dd.col[N - 1]]++;

        v1.push_back(dd);
    }
    int trainData = 0;
    classes = deci.size();
    for(auto it = deci.begin(); it != deci.end(); it++){
        cnt[it -> first] = it -> second * 9;
        cnt[it -> first] /= 10;
        trainData += cnt[it -> first];
    }

    cout << "Size: " << v1.size() << endl;

    while(true){
        if(!trainData)break;
        int val = rand() % v1.size();
       // cout << val << " " << v1[val].col[N - 1] << endl;
      //  cout << val << " " << cnt0 << " " << cnt1 << " " << v1.size() << endl;
        if(cnt[v1[val].col[N - 1]]){
            v.push_back(v1[val]);
            cnt[v1[val].col[N - 1]]--;
            v1.erase(v1.begin() + val);
            trainData--;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < v.size(); j++){
            total[i] += (double) v[j].col[i];
        }
    }
    for(int i = 0; i < N; i++){
        average[i] = (double) total[i] / (v.size()) * 1.0;

    }


}

void writeFile(int maxi){
    ofstream name("trainData.txt");
    for(int i = 0; i < columns.size(); i++){
        name << columns[i] << " ";
    }
    name << endl;
    for(int i = 0; i <= maxi; i++){
        name << con[i].ind << " " << con[i].value << " " << con[i].decision << " " << con[i].ans << " " << con[i].leftChild << " " << con[i].rightChild << endl;
    }
}

void readData(){
    ifstream name("trainData.txt");
    string s;
    getline(name, s);

    istringstream iss(s);
    while(iss >> s){
        columns.push_back(s);
    }
    int i = 0;

    while(getline(name, s)){
        istringstream iss(s);
        iss >> con[i].ind >> con[i].value >> con[i].decision >> con[i].ans >> con[i].leftChild >> con[i].rightChild;
        i++;
    }
    cout << i << " lines were read.\n";
}

int res[2][2];
int main(){
    readFile();

    recursion(0, 0, v.size() - 1, average, 1);
    cout << "Total Trained Data: " << v.size() << endl;
    cout << "Total Test Data: " << v1.size() << endl;
    cout << "Height of the tree: " << H << endl;
    cout << "Total Nodes of the tree: " << maxi + 1 << endl;
    writeFile(maxi);

    for(int i = 0; i < v1.size(); i++){
        data d;
        d = v1[i];
        cout << "Test Data #" << i + 1 << "\n";
        int result = query(0, d);
        cout << "Decision: " << result << endl;
        cout << "Real Answer: " << d.col[N - 1] << endl;
        cout << "-----------------------------------\n";
        if(classes == 2)res[result][(int) d.col[N - 1]]++;

    }
    if(classes == 2){
        string a[2][2];
        a[1][1] = "True Positive (tp)";
        a[0][0] = "True Negative (tn)";
        a[1][0] = "False Positive (fp)";
        a[0][1] = "False Negative (fn)";

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                cout << a[i][j] << ": " << res[i][j] << endl;
            }
        }
        cout << "Precision: ";
        cout << fixed << setprecision(6) << (double) res[1][1] / (res[1][1] + res[1][0]) << endl;
        cout << "Recall: ";
        cout << fixed << setprecision(6) << (double) res[1][1] / (res[1][1] + res[0][1]) << endl;
        cout << "Accuracy: ";
        cout << fixed << setprecision(6) << (double) (res[1][1] + res[0][0])/ (res[1][1] + res[1][0] + res[0][0] + res[0][1]) << endl;
        cout << "F-measure: ";
        cout << fixed << setprecision(6) << (double) (2.0 * res[1][1])/ (2 * res[1][1] + res[1][0] + res[0][1]) << endl;

    }

}
