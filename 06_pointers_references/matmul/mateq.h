bool mateq(int** a, int m_a, int n_a, int** b, int m_b, int n_b)
{
    bool f = true;
    if (m_a != m_b || n_a != n_b) return f = false;
    else {
        for (int i = 0; i < m_a; i++) {
            for (int j = 0; j < n_a; j++) {
                if (a[i][j] != b[i][j]) return f = false;
            }
        }

        return f = true;
    }
}