#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <queue>

int rc_to_num(int r, int c) {
  return r * 8 + c;
}

std::pair<int, int> num_to_rc(int num) {
  return std::make_pair(num / 8, num % 8);
}

bool valid(int r, int c) {
  return r >= 0 && r <= 7 && c >= 0 && c <= 7;
}

std::vector<int> children(int u) {
  // 0 <= u <= 63
  std::pair<int, int> u_p = num_to_rc(u);
  int ur = u_p.first;
  int uc = u_p.second;
  std::vector<int> cs;

  if (valid(ur - 2, uc - 1)) {
    cs.push_back(rc_to_num(ur - 2, uc - 1));
  }
  
  if (valid(ur - 2, uc + 1)) {
    cs.push_back(rc_to_num(ur - 2, uc + 1));
  }

  if (valid(ur - 1, uc - 2)) {
    cs.push_back(rc_to_num(ur - 1, uc - 2));
  }

  if (valid(ur + 1, uc - 2)) {
    cs.push_back(rc_to_num(ur + 1, uc - 2));
  }

  if (valid(ur + 2, uc - 1)) {
    cs.push_back(rc_to_num(ur + 2, uc - 1));
  }

  if (valid(ur + 2, uc + 1)) {
    cs.push_back(rc_to_num(ur + 2, uc + 1));
  }

  if (valid(ur - 1, uc + 2)) {
    cs.push_back(rc_to_num(ur - 1, uc + 2));
  }

  if (valid(ur + 1, uc + 2)) {
    cs.push_back(rc_to_num(ur + 1, uc + 2));
  }

  return cs;
}

int shortest_path(int src, int dst) {
  std::vector<bool> visited (64, false);
  std::queue<int> q;
  std::vector<int> dist (64, -1);

  visited[src] = true;
  q.push(src);
  dist[src] = 0;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    if (cur == dst) break;

    std::vector<int> cs = children(cur);
    for (int c: cs) {
      if (!visited[c]) {
        visited[c] = true;
        dist[c] = dist[cur] + 1;
        q.push(c);
      }
    }
  }

  return dist[dst];
}

int main(void) {
  int t;
  std::cin >> t;

  for (int tc = 0; tc < t; ++tc) {
    std::string src;
    std::string dst;
    std::cin >> src >> dst;

    int src_r = src[1] - '1';
    int src_c = src[0] - 'a';
    int dst_r = dst[1] - '1';
    int dst_c = dst[0] - 'a';
    int src_num = rc_to_num(src_r, src_c);
    int dst_num = rc_to_num(dst_r, dst_c);

    std::cout << shortest_path(src_num, dst_num) << std::endl;
  }

  return 0;
}
