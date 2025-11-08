void DFS(int start) {
    stack<int> st;
    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        cout << u << " "; // xử lý đỉnh u

        for (int v : adj[u]) {
            if (!visited[v]) {
                st.push(v);
                visited[v] = true;
            }
        }
    }
}
