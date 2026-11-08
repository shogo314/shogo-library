---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: src/graph/tree.hpp
    title: "\u6728\u306E\u6C4E\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/graph/tree-member.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ tree.hpp \u306E Tree \u3067\u516C\u958B\u3057\u3066\u3044\u308B\u30E1\u30F3\u30D0\
    \u3092\u691C\u8A3C\u3059\u308B\n// add_directed_edge \u306F\u5916\u304B\u3089\u547C\
    \u3079\u306A\u3044\u3053\u3068 (RootedTree\u30FBDoublingClimbTree \u3067\u3082\
    ) \u3092\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u306B\u78BA\u304B\u3081\u308B\n//\
    \ add_edge \u3068\u3001cin \u3092\u5DEE\u3057\u66FF\u3048\u305F read \u3067\u4F5C\
    \u3063\u305F\u6728\u306E\u8FBA\u3092\u78BA\u304B\u3081\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include <iostream>\n\
    #include <sstream>\n#include <type_traits>\n#include <utility>\n\n#line 2 \"src/graph/tree.hpp\"\
    \n\n/**\n * @file tree.hpp\n * @brief \u6728\u306E\u6C4E\u7528\u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n */\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <stack>\n#line 13 \"src/graph/tree.hpp\"\n#include <vector>\n\n#line 2 \"src/graph/graph.hpp\"\
    \n\n/**\n * @file graph.hpp\n * @brief \u30B0\u30E9\u30D5\n */\n\n#line 12 \"\
    src/graph/graph.hpp\"\n\n/**\n * @brief \u30B0\u30E9\u30D5\u306E\u6C4E\u7528\u30AF\
    \u30E9\u30B9\n *\n * @tparam Cost \u8FBA\u306E\u30B3\u30B9\u30C8\u306E\u578B \u7701\
    \u7565\u3057\u305F\u3089 long long (\u91CD\u307F\u306E\u548C\u3084\u672A\u5230\
    \u9054\u3092\u8868\u3059 max / 4 \u304C\u3042\u3075\u308C\u306B\u304F\u3044\u3088\
    \u3046\u306B)\n */\ntemplate <typename Cost = long long>\nclass Graph {\n   public:\n\
    \    /**\n     * @brief \u6709\u5411\u8FBA\u306E\u69CB\u9020\u4F53\n     *\n \
    \    * operator long long()\u3092\u5B9A\u7FA9\u3057\u3066\u3044\u308B\u306E\u3067\
    \u3001\u6574\u6570\u578B\u306B\u30AD\u30E3\u30B9\u30C8\u3059\u308B\u3068\u52DD\
    \u624B\u306Bdst\u306B\u306A\u308B\n     * \u4F8B\u3048\u3070\u3001\n     * for\
    \ (auto& e : g[v]) \u3092\u3059\u308B\u3068\u3001v\u304B\u3089\u51FA\u308B\u8FBA\
    \u304C\u5217\u6319\u3055\u308C\u308B\u304C\u3001\n     * for (long long dst :\
    \ g[v]) \u3068\u3059\u308B\u3068\u3001v\u304B\u3089\u51FA\u308B\u8FBA\u306E\u884C\
    \u304D\u5148\u304C\u5217\u6319\u3055\u308C\u308B\n     */\n    struct Edge {\n\
    \        long long src = -1;  //!< \u59CB\u70B9\n        long long dst = -1; \
    \ //!< \u7D42\u70B9\n        Cost cost = {};      //!< \u30B3\u30B9\u30C8\n  \
    \      long long id = -1;   //!< \u8FBA\u306E\u756A\u53F7(\u8FFD\u52A0\u3055\u308C\
    \u305F\u9806\u3001\u7121\u5411\u8FBA\u306E\u5834\u5408\u306Fid\u304C\u540C\u3058\
    \u3067\u65B9\u5411\u304C\u9006\u306E\u3082\u306E\u304C2\u3064\u5B58\u5728\u3059\
    \u308B)\n        Edge() = default;\n        Edge(long long src, long long dst,\
    \ Cost cost = 1, long long id = -1) : src(src), dst(dst), cost(cost), id(id) {}\n\
    \        operator long long() const { return dst; }\n    };\n\n   private:\n \
    \   long long n;                       //!< \u9802\u70B9\u6570\n    long long\
    \ m;                       //!< \u8FBA\u6570\n    std::vector<std::vector<Edge>>\
    \ g;  //!< \u30B0\u30E9\u30D5\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u8868\u73FE\n\
    \n   public:\n    /**\n     * @brief \u30C7\u30D5\u30A9\u30EB\u30C8\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n     */\n    Graph() : n(0), m(0), g(0) {}\n \
    \   /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param\
    \ n \u9802\u70B9\u6570\n     */\n    explicit Graph(long long n) : n(n), m(0),\
    \ g(n) {}\n    /**\n     * @brief \u9802\u70B9\u6570\n     */\n    long long size()\
    \ const { return n; }\n    /**\n     * @brief \u8FBA\u6570 (\u7121\u5411\u8FBA\
    \u306F 1 \u672C\u3068\u6570\u3048\u308B)\n     */\n    long long edge_count()\
    \ const { return m; }\n    /**\n     * @brief \u7121\u5411\u8FBA\u3092\u8FFD\u52A0\
    \u3059\u308B\n     * @param u \u59CB\u70B9\n     * @param v \u7D42\u70B9\n   \
    \  * @param w \u30B3\u30B9\u30C8 \u7701\u7565\u3057\u305F\u30891\n     */\n  \
    \  void add_edge(long long u, long long v, Cost w = 1) {\n        assert(0 <=\
    \ u && u < n && 0 <= v && v < n);\n        g[u].push_back({u, v, w, m});\n   \
    \     g[v].push_back({v, u, w, m++});\n    }\n    /**\n     * @brief \u6709\u5411\
    \u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n     * @param u \u59CB\u70B9\n     * @param\
    \ v \u7D42\u70B9\n     * @param w \u30B3\u30B9\u30C8 \u7701\u7565\u3057\u305F\u3089\
    1\n     */\n    void add_directed_edge(long long u, long long v, Cost w = 1) {\n\
    \        assert(0 <= u && u < n && 0 <= v && v < n);\n        g[u].push_back({u,\
    \ v, w, m++});\n    }\n    /**\n     * @brief \u8FBA\u306E\u60C5\u5831\u3092\u6A19\
    \u6E96\u5165\u529B\u304B\u3089\u53D7\u3051\u53D6\u3063\u3066\u8FFD\u52A0\u3059\
    \u308B\n     * @param m \u8FBA\u306E\u6570\n     * @param padding \u9802\u70B9\
    \u756A\u53F7\u3092\u5165\u529B\u304B\u3089\u3044\u304F\u3064\u305A\u3089\u3059\
    \u304B \u7701\u7565\u3057\u305F\u3089-1\n     * @param weighted \u8FBA\u306E\u91CD\
    \u307F\u304C\u5165\u529B\u3055\u308C\u308B\u304B \u7701\u7565\u3057\u305F\u3089\
    false\u3068\u306A\u308A\u3001\u91CD\u307F1\u3067\u8FBA\u304C\u8FFD\u52A0\u3055\
    \u308C\u308B\n     * @param directed \u6709\u5411\u30B0\u30E9\u30D5\u304B\u3069\
    \u3046\u304B \u7701\u7565\u3057\u305F\u3089false\n     */\n    void read(long\
    \ long m, long long padding = -1, bool weighted = false, bool directed = false)\
    \ {\n        for (long long i = 0; i < m; i++) {\n            long long u, v;\n\
    \            std::cin >> u >> v;\n            u += padding, v += padding;\n  \
    \          Cost c(1);\n            if (weighted)\n                std::cin >>\
    \ c;\n            if (directed)\n                add_directed_edge(u, v, c);\n\
    \            else\n                add_edge(u, v, c);\n        }\n    }\n    /**\n\
    \     * @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u51FA\u308B\u8FBA\u3092\u5217\
    \u6319\u3059\u308B\n     * @param v \u9802\u70B9\u756A\u53F7\n     * @return const\
    \ std::vector<Edge>& v\u304B\u3089\u51FA\u308B\u8FBA\u306E\u30EA\u30B9\u30C8\n\
    \     */\n    const std::vector<Edge>& operator[](long long v) const {\n     \
    \   assert(0 <= v && v < n);\n        return g[v];\n    }\n    /**\n     * @brief\
    \ \u8FBA\u306E\u30EA\u30B9\u30C8\n     * @return std::vector<Edge> \u8FBA\u306E\
    \u30EA\u30B9\u30C8(id\u306E\u6607\u9806)\n     *\n     * \u7121\u5411\u8FBA\u306F\
    \u4EE3\u8868\u3057\u30661\u3064\u3060\u3051\u683C\u7D0D\u3055\u308C\u308B\u3002\
    \u305D\u306E src \u3068 dst \u306E\u5411\u304D\u306F\u898F\u5B9A\u3057\u306A\u3044\
    \n     * \u6709\u5411\u8FBA\u306F\u8FFD\u52A0\u3057\u305F\u3068\u304D\u306E\u5411\
    \u304D\u306E\u307E\u307E\u683C\u7D0D\u3055\u308C\u308B\n     */\n    std::vector<Edge>\
    \ edges() const {\n        std::vector<Edge> res(m);\n        for (long long i\
    \ = 0; i < n; i++) {\n            for (auto& e : g[i]) {\n                res[e.id]\
    \ = e;\n            }\n        }\n        return res;\n    }\n};\n\n/**\n * @brief\
    \ \u7D4C\u8DEF (\u8DEF\u30FB\u9589\u8DEF)\u3002\u9577\u3055 cost\u3001\u305F\u3069\
    \u308B\u9802\u70B9\u306E\u5217 vertices\u3001\u305F\u3069\u308B\u8FBA\u306E\u5217\
    \ edges\n *\n * edges[k] \u306F vertices[k] \u304B\u3089 vertices[k + 1] \u3078\
    \u5411\u304B\u3046 (edges[k].src == vertices[k]\u3001edges[k].dst == vertices[k\
    \ + 1])\n * vertices \u306F edges \u3088\u308A 1 \u3064\u591A\u3044\u3002\u8FBA\
    \u304C\u306A\u304F\u3066\u3082\u59CB\u70B9 1 \u3064\u304C\u5165\u308B\u3002\u9589\
    \u8DEF\u306A\u3089 vertices.front() == vertices.back()\n * auto [cost, vertices,\
    \ edges] = *shortest_path(g, s, t); \u306E\u3088\u3046\u306B\u53D7\u3051\u53D6\
    \u308C\u308B\n */\ntemplate <typename Cost>\nstruct Path {\n    Cost cost;   \
    \                                   //!< \u9577\u3055 (\u8FBA\u306E\u30B3\u30B9\
    \u30C8\u306E\u548C)\n    std::vector<long long> vertices;                //!<\
    \ \u305F\u3069\u308B\u9802\u70B9 (\u59CB\u70B9\u304B\u3089\u9806\u306B)\n    std::vector<typename\
    \ Graph<Cost>::Edge> edges;  //!< \u305F\u3069\u308B\u8FBA (\u59CB\u70B9\u5074\
    \u304B\u3089\u9806\u306B)\n};\n\nnamespace internal_graph {\n/**\n * @brief \u59CB\
    \u70B9 s \u3068\u3001s \u304B\u3089\u305F\u3069\u308B\u9806\u306B\u4E26\u3079\u305F\
    \u8FBA edges \u304B\u3089 Path \u3092\u4F5C\u308B\u3002cost \u306F\u8FBA\u306E\
    \u30B3\u30B9\u30C8\u306E\u548C\n */\ntemplate <typename Cost>\nPath<Cost> make_path(long\
    \ long s, std::vector<typename Graph<Cost>::Edge> edges) {\n    Path<Cost> res{Cost{},\
    \ {s}, std::move(edges)};\n    for (const auto& e : res.edges) {\n        assert(e.src\
    \ == res.vertices.back());\n        res.cost += e.cost;\n        res.vertices.push_back(e.dst);\n\
    \    }\n    return res;\n}\n}  // namespace internal_graph\n#line 16 \"src/graph/tree.hpp\"\
    \n\ntemplate <typename>\nclass RootedTree;\ntemplate <typename>\nclass DoublingClimbTree;\n\
    \n/**\n * @brief \u6839\u306A\u3057\u6728\n *\n * @tparam Cost = long long \u8FBA\
    \u306E\u91CD\u307F\n *\n * Graph<Cost>\u3092\u7D99\u627F\u3057\u3001\u3059\u3079\
    \u3066\u7121\u5411\u8FBA\u3067\u8868\u3059\n */\ntemplate <typename Cost = long\
    \ long>\nstruct Tree : private Graph<Cost> {\n    // Graph<Cost>* g = new Tree<Cost>();\
    \ \u304C\u3067\u304D\u3066\u3057\u307E\u3046\u3068\u3001delete\u6642\u306B\u30E1\
    \u30E2\u30EA\u30EA\u30FC\u30AF\u304C\u767A\u751F\n    // \u56DE\u907F\u3059\u308B\
    \u305F\u3081private\u7D99\u627F\u306B\u3057\u3066\u3001\u516C\u958B\u3059\u308B\
    \u30E1\u30F3\u30D0\u3092using\u5BA3\u8A00\u3059\u308B\n    // add_directed_edge\
    \ \u306F\u6728\u3067\u306A\u304F\u306A\u308B\u306E\u3067\u516C\u958B\u3057\u306A\
    \u3044 (read \u306F Tree::read \u3067\u96A0\u3059)\n    using Edge = typename\
    \ Graph<Cost>::Edge;\n    using Graph<Cost>::size;\n    using Graph<Cost>::edge_count;\n\
    \    using Graph<Cost>::Graph;\n    using Graph<Cost>::add_edge;\n    using Graph<Cost>::operator[];\n\
    \    using Graph<Cost>::edges;\n\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\n     *\n     * @param n \u30CE\u30FC\u30C9\u6570\n     */\n\
    \    explicit Tree(long long n = 0) : Graph<Cost>(n) {}\n\n    /**\n     * @brief\
    \ Graph \u3068\u3057\u3066\u898B\u308B\n     *\n     * Graph \u3092\u53D7\u3051\
    \u53D6\u308B\u95A2\u6570 (shortest_path_dijkstra \u306A\u3069) \u306B\u6E21\u3059\
    \u3068\u304D\u306B\u4F7F\u3046\n     * @return const Graph<Cost>& \u3053\u306E\
    \u6728\u3092\u8868\u3059\u30B0\u30E9\u30D5\n     */\n    const Graph<Cost>& graph()\
    \ const { return *this; }\n\n    /**\n     * @brief \u8FBA\u306E\u60C5\u5831\u3092\
    \u6A19\u6E96\u5165\u529B\u304B\u3089\u53D7\u3051\u53D6\u3063\u3066\u8FFD\u52A0\
    \u3059\u308B\n     * @param padding  = -1 \u9802\u70B9\u756A\u53F7\u3092\u5165\
    \u529B\u304B\u3089\u3044\u304F\u3064\u305A\u3089\u3059\u304B\n     * @param weighted\
    \ = false \u8FBA\u306E\u91CD\u307F\u304C\u5165\u529B\u3055\u308C\u308B\u304B\n\
    \     */\n    void read(long long padding = -1, bool weighted = false) {\n   \
    \     Graph<Cost>::read(this->size() - 1, padding, weighted, false);\n    }\n\n\
    \    /**\n     * @brief \u6839\u4ED8\u304D\u6728\u306B\u3059\u308B\n     *\n \
    \    * @param root \u6839\n     * @return RootedTree<Cost> \u6839\u4ED8\u304D\u6728\
    \u306E\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\n     */\n    [[nodiscard]]\n    RootedTree<Cost>\
    \ set_root(long long root) const& {\n        return RootedTree<Cost>(*this, root);\n\
    \    }\n    /**\n     * @brief \u6839\u4ED8\u304D\u6728\u306B\u3057\u3066\u8FD4\
    \u3059\n     *\n     * @param root \u6839\n     * @return RootedTree<Cost> \u6839\
    \u4ED8\u304D\u6728\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\n     */\n    [[nodiscard]]\n\
    \    RootedTree<Cost> set_root(long long root) && {\n        return RootedTree<Cost>(std::move(*this),\
    \ root);\n    }\n\n    /**\n     * @brief \u30C0\u30D6\u30EA\u30F3\u30B0LCA\u304C\
    \u4F7F\u3048\u308B\u6839\u4ED8\u304D\u6728\u3092\u8FD4\u3059\n     *\n     * @param\
    \ root \u6839\n     * @return DoublingClimbTree<Cost> \u30C0\u30D6\u30EA\u30F3\
    \u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n     */\n    [[nodiscard]]\n    DoublingClimbTree<Cost> build_lca(long\
    \ long root) const& {\n        RootedTree rooted_tree(*this, root);\n        return\
    \ DoublingClimbTree<Cost>(std::move(rooted_tree));\n    }\n    /**\n     * @brief\
    \ \u30C0\u30D6\u30EA\u30F3\u30B0LCA\u304C\u4F7F\u3048\u308B\u6839\u4ED8\u304D\u6728\
    \u3092\u8FD4\u3059\n     *\n     * @param root \u6839\n     * @return DoublingClimbTree<Cost>\
    \ \u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u306E\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\n     */\n    [[nodiscard]]\n    DoublingClimbTree<Cost>\
    \ build_lca(long long root) && {\n        RootedTree rooted_tree(std::move(*this),\
    \ root);\n        return DoublingClimbTree<Cost>(std::move(rooted_tree));\n  \
    \  }\n};\n\n/**\n * @brief \u6839\u4ED8\u304D\u6728\n *\n * @tparam Cost = long\
    \ long \u8FBA\u306E\u30B3\u30B9\u30C8\n */\ntemplate <typename Cost = long long>\n\
    class RootedTree : private Tree<Cost> {\n   public:\n    using Edge = typename\
    \ Tree<Cost>::Edge;\n    using Tree<Cost>::size;\n    using Tree<Cost>::edge_count;\n\
    \    using Tree<Cost>::edges;\n    using Tree<Cost>::graph;\n\n   private:\n \
    \   long long _root;                                           //!< \u6839\n \
    \   std::vector<Edge> _par;                                    //!< \u89AA\u3078\
    \u5411\u304B\u3046\u8FBA\n    std::vector<std::vector<Edge>> _child;         \
    \            //!< \u5B50\u3078\u5411\u304B\u3046\u8FBA\u306E\u30EA\u30B9\u30C8\
    \n    std::vector<Cost> _depth;                                  //!< \u6DF1\u3055\
    \u306E\u30EA\u30B9\u30C8\n    std::vector<Cost> _height;                     \
    \            //!< \u90E8\u5206\u6728\u306E\u9AD8\u3055\u306E\u30EA\u30B9\u30C8\
    \n    std::vector<long long> _unweighted_depth;                  //!< \u91CD\u307F\
    \u306A\u3057\u306E\u6DF1\u3055\u306E\u30EA\u30B9\u30C8\n    std::vector<long long>\
    \ _unweighted_height;                 //!< \u91CD\u307F\u306A\u3057\u306E\u90E8\
    \u5206\u6728\u306E\u9AD8\u3055\u306E\u30EA\u30B9\u30C8\n    std::vector<long long>\
    \ _sz;                                //!< \u90E8\u5206\u6728\u306E\u9802\u70B9\
    \u6570\u306E\u30EA\u30B9\u30C8\n    std::vector<long long> _preorder;        \
    \                  //!< \u5148\u884C\u9806\u5DE1\u56DE\n    std::vector<long long>\
    \ _postorder;                         //!< \u5F8C\u884C\u9806\u5DE1\u56DE\n  \
    \  std::vector<std::pair<long long, long long>> _euler_tour;  //!< \u30AA\u30A4\
    \u30E9\u30FC\u30C4\u30A2\u30FC DFS\u4E2D\u306B\u3068\u304A\u3063\u305F\u9802\u70B9\
    \u306E(\u9802\u70B9\u756A\u53F7,\u305D\u306E\u9802\u70B9\u3092\u901A\u3063\u305F\
    \u56DE\u6570)\u306E\u30EA\u30B9\u30C8\n\n   public:\n    /**\n     * @brief \u9802\
    \u70B9 v \u304B\u3089\u51FA\u308B\u8FBA\u3092\u5217\u6319\u3059\u308B\n     */\n\
    \    const std::vector<Edge>& operator[](long long v) const { return Tree<Cost>::operator[](v);\
    \ }\n\n    /** @brief \u6839 */\n    long long root() const { return _root; }\n\
    \    /** @brief \u9802\u70B9 v \u306E\u89AA\u3078\u5411\u304B\u3046\u8FBA (\u6839\
    \u3067\u306F dst == -1) */\n    const Edge& parent_edge(long long v) const {\n\
    \        assert(0 <= v && v < size());\n        return _par[v];\n    }\n    /**\
    \ @brief \u9802\u70B9 v \u306E\u5B50\u3078\u5411\u304B\u3046\u8FBA */\n    const\
    \ std::vector<Edge>& children(long long v) const {\n        assert(0 <= v && v\
    \ < size());\n        return _child[v];\n    }\n    /** @brief \u9802\u70B9 v\
    \ \u306E\u6839\u304B\u3089\u306E\u8DDD\u96E2 */\n    Cost depth(long long v) const\
    \ {\n        assert(0 <= v && v < size());\n        return _depth[v];\n    }\n\
    \    /** @brief \u9802\u70B9 v \u306E\u90E8\u5206\u6728\u306E\u9AD8\u3055 */\n\
    \    Cost height(long long v) const {\n        assert(0 <= v && v < size());\n\
    \        return _height[v];\n    }\n    /** @brief \u9802\u70B9 v \u306E\u6839\
    \u304B\u3089\u306E\u8FBA\u6570 */\n    long long unweighted_depth(long long v)\
    \ const {\n        assert(0 <= v && v < size());\n        return _unweighted_depth[v];\n\
    \    }\n    /** @brief \u9802\u70B9 v \u306E\u90E8\u5206\u6728\u306E\u9AD8\u3055\
    \ (\u8FBA\u6570) */\n    long long unweighted_height(long long v) const {\n  \
    \      assert(0 <= v && v < size());\n        return _unweighted_height[v];\n\
    \    }\n    /** @brief \u9802\u70B9 v \u306E\u90E8\u5206\u6728\u306E\u9802\u70B9\
    \u6570 */\n    long long subtree_size(long long v) const {\n        assert(0 <=\
    \ v && v < size());\n        return _sz[v];\n    }\n    /** @brief \u884C\u304D\
    \u304C\u3051\u9806 */\n    const std::vector<long long>& preorder() const { return\
    \ _preorder; }\n    /** @brief \u5E30\u308A\u304C\u3051\u9806 */\n    const std::vector<long\
    \ long>& postorder() const { return _postorder; }\n    /** @brief \u30AA\u30A4\
    \u30E9\u30FC\u30C4\u30A2\u30FC (\u9802\u70B9\u3068\u8A2A\u554F\u56DE\u6570\u306E\
    \u7D44) */\n    const std::vector<std::pair<long long, long long>>& euler_tour()\
    \ const { return _euler_tour; }\n\n    RootedTree() = delete;\n\n    /**\n   \
    \  * @brief \u89AA\u306E\u9802\u70B9\u306E\u30EA\u30B9\u30C8\u304B\u3089\u6839\
    \u304C0\u306E\u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @tparam T \u9802\u70B9\u756A\u53F7\
    \u306E\u6574\u6570\u578B (long long \u3084 int)\n     * @param par_ \u9802\u70B9\
    0\u4EE5\u5916\u306E\u89AA\u306E\u9802\u70B9\u306E\u30EA\u30B9\u30C8\n     * @param\
    \ padding = -1 par\u306E\u9802\u70B9\u756A\u53F7\u3092\u3044\u304F\u3064\u305A\
    \u3089\u3059\u304B\n     */\n    template <typename T = long long>\n    explicit\
    \ RootedTree(const std::vector<T>& par_, long long padding = -1) : Tree<Cost>(par_.size()\
    \ + 1), _root(0) {\n        static_assert(std::is_integral_v<T>, \"RootedTree:\
    \ par_ must be a vector of integers\");\n        for (long long i = 0; i < static_cast<long\
    \ long>(par_.size()); i++) {\n            this->add_edge(i + 1, par_[i] + padding);\n\
    \        }\n        build();\n    }\n    /**\n     * @brief Tree\u304B\u3089\u6839\
    \u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF(\u30B3\u30D4\u30FC)\n     *\n     * @param tree Tree \u9802\u70B9\
    \u65701\u4EE5\u4E0A\n     * @param root \u6839\n     */\n    RootedTree(const\
    \ Tree<Cost>& tree, long long root) : Tree<Cost>(tree), _root(root) {\n      \
    \  build();\n    }\n    /**\n     * @brief Tree\u304B\u3089\u6839\u4ED8\u304D\u6728\
    \u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF(\u30E0\
    \u30FC\u30D6)\n     *\n     * @param tree Tree\n     * @param root \u6839\n  \
    \   */\n    RootedTree(Tree<Cost>&& tree, long long root) : Tree<Cost>(std::move(tree)),\
    \ _root(root) {\n        build();\n    }\n\n    /**\n     * @brief \u30C0\u30D6\
    \u30EA\u30F3\u30B0LCA\u304C\u4F7F\u3048\u308B\u6839\u4ED8\u304D\u6728\u3092\u5F97\
    \u308B\n     *\n     * @return DoublingClimbTree<Cost> \u30C0\u30D6\u30EA\u30F3\
    \u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n     */\n    [[nodiscard]]\n    DoublingClimbTree<Cost> build_lca() const&\
    \ {\n        return DoublingClimbTree<Cost>(*this);\n    }\n\n    /**\n     *\
    \ @brief \u30C0\u30D6\u30EA\u30F3\u30B0LCA\u304C\u4F7F\u3048\u308B\u6839\u4ED8\
    \u304D\u6728\u3092\u5F97\u308B\n     *\n     * @return DoublingClimbTree<Cost>\
    \ \u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u306E\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\n     */\n    [[nodiscard]]\n    DoublingClimbTree<Cost>\
    \ build_lca() && {\n        return DoublingClimbTree<Cost>(std::move(*this));\n\
    \    }\n\n   private:\n    void build() {\n        long long n = this->size();\n\
    \        assert(n > 0);\n        assert(0 <= _root && _root < n);\n        _par.resize(n);\n\
    \        _par[_root] = {_root, -1, 0, -1};\n        _child.resize(n);\n      \
    \  _depth.resize(n);\n        _unweighted_depth.resize(n);\n        _height.resize(n);\n\
    \        _unweighted_height.resize(n);\n        _sz.resize(n);\n        std::vector<int>\
    \ iter(n);\n        std::stack<std::pair<int, int>> stk;\n        stk.emplace(_root,\
    \ 0);\n        while (!stk.empty()) {\n            auto [u, cnt] = stk.top();\n\
    \            stk.pop();\n            _euler_tour.emplace_back(u, cnt);\n     \
    \       if (iter[u] == 0) _preorder.push_back(u);\n            while (iter[u]\
    \ < static_cast<int>((*this)[u].size()) && (*this)[u][iter[u]].dst == _par[u])\
    \ iter[u]++;\n            if (iter[u] == static_cast<int>((*this)[u].size()))\
    \ {\n                _postorder.push_back(u);\n                _sz[u] = 1;\n \
    \               _height[u] = 0;\n                _unweighted_height[u] = 0;\n\
    \                for (auto& e : _child[u]) {\n                    _sz[u] += _sz[e.dst];\n\
    \                    if (_height[u] < _height[e.dst] + e.cost) {\n           \
    \             _height[u] = _height[e.dst] + e.cost;\n                    }\n \
    \                   if (_unweighted_height[u] < _unweighted_height[e.dst] + 1)\
    \ {\n                        _unweighted_height[u] = _unweighted_height[e.dst]\
    \ + 1;\n                    }\n                }\n            } else {\n     \
    \           auto& e = (*this)[u][iter[u]++];\n                _par[e.dst] = {e.dst,\
    \ u, e.cost, e.id};\n                _child[u].push_back(e);\n               \
    \ _depth[e.dst] = _depth[u] + e.cost;\n                _unweighted_depth[e.dst]\
    \ = _unweighted_depth[u] + 1;\n                stk.emplace(u, cnt + 1);\n    \
    \            stk.emplace(e.dst, 0);\n            }\n        }\n    }\n};\n\n/**\n\
    \ * @brief \u89AA\u9802\u70B9\u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\
    \u304D\u6728\n *\n * @tparam Cost = long long \u8FBA\u306E\u91CD\u307F(\u6CE8\
    : hop\u3067\u306F\u6839\u306E\u91CD\u307F\u306F\u8003\u3048\u306A\u3044)\n */\n\
    template <typename Cost = long long>\nclass DoublingClimbTree : private RootedTree<Cost>\
    \ {\n   public:\n    using Edge = typename RootedTree<Cost>::Edge;\n    using\
    \ RootedTree<Cost>::size;\n    using RootedTree<Cost>::edge_count;\n    using\
    \ RootedTree<Cost>::operator[];\n    using RootedTree<Cost>::edges;\n    using\
    \ RootedTree<Cost>::graph;\n    using RootedTree<Cost>::root;\n    using RootedTree<Cost>::parent_edge;\n\
    \    using RootedTree<Cost>::children;\n    using RootedTree<Cost>::depth;\n \
    \   using RootedTree<Cost>::height;\n    using RootedTree<Cost>::unweighted_depth;\n\
    \    using RootedTree<Cost>::unweighted_height;\n    using RootedTree<Cost>::subtree_size;\n\
    \    using RootedTree<Cost>::preorder;\n    using RootedTree<Cost>::postorder;\n\
    \    using RootedTree<Cost>::euler_tour;\n\n   private:\n    long long h;    \
    \                                   //!< \u30C0\u30D6\u30EA\u30F3\u30B0\u306E\u56DE\
    \u6570\n    std::vector<std::vector<long long>> doubling_par;  //!< j\u304B\u3089\
    (1<<i)\u9802\u70B9\u767B\u3063\u305F\u9802\u70B9(\u5B58\u5728\u3057\u306A\u3044\
    \u5834\u5408\u306F-1)\n\n   public:\n    DoublingClimbTree() = delete;\n\n   \
    \ /**\n     * @brief RootedTree\u304B\u3089\u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\
    \u307F\u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF(\u30B3\u30D4\u30FC)\n     *\n     * @param tree RootedTree\n\
    \     */\n    explicit DoublingClimbTree(const RootedTree<Cost>& tree) : RootedTree<Cost>(tree)\
    \ {\n        build();\n    }\n\n    /**\n     * @brief RootedTree\u304B\u3089\u30C0\
    \u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\
    \u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF(\u30E0\u30FC\u30D6)\n \
    \    *\n     * @param tree RootedTree\n     */\n    DoublingClimbTree(RootedTree<Cost>&&\
    \ tree) : RootedTree<Cost>(std::move(tree)) {\n        build();\n    }\n\n   \
    \ /**\n     * @brief \u89AA\u306E\u9802\u70B9\u306E\u30EA\u30B9\u30C8\u304B\u3089\
    \u6839\u304C0\u306E\u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\
    \u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \n     *\n     * @tparam T \u9802\u70B9\u756A\u53F7\u306E\u6574\u6570\u578B (long\
    \ long \u3084 int)\n     * @param par_ \u9802\u70B90\u4EE5\u5916\u306E\u89AA\u306E\
    \u9802\u70B9\u306E\u30EA\u30B9\u30C8\n     * @param padding = -1 par\u306E\u9802\
    \u70B9\u756A\u53F7\u3092\u3044\u304F\u3064\u305A\u3089\u3059\u304B\n     */\n\
    \    template <typename T = long long>\n    explicit DoublingClimbTree(const std::vector<T>&\
    \ par_, long long padding = -1) : RootedTree<Cost>(par_, padding) {\n        build();\n\
    \    }\n    /**\n     * @brief Tree\u304B\u3089\u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\
    \u307F\u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF(\u30B3\u30D4\u30FC)\n     *\n     * @param tree Tree\n\
    \     * @param root \u6839\n     */\n    DoublingClimbTree(const Tree<Cost>& tree,\
    \ long long root) : RootedTree<Cost>(tree, root) {\n        build();\n    }\n\
    \    /**\n     * @brief Tree\u304B\u3089\u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\
    \u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF(\u30E0\u30FC\u30D6)\n     *\n     * @param tree Tree\n    \
    \ * @param root \u6839\n     */\n    DoublingClimbTree(Tree<Cost>&& tree, long\
    \ long root) : RootedTree<Cost>(std::move(tree), root) {\n        build();\n \
    \   }\n\n    /**\n     * @brief \u9802\u70B9u\u304B\u3089k\u56DE\u3092\u6839\u306E\
    \u65B9\u5411\u306B\u9061\u3063\u305F\u9802\u70B9\n     *\n     * @param u \u5143\
    \u306E\u9802\u70B9\n     * @param k \u767B\u308B\u6BB5\u6570\n     * @return long\
    \ long k\u56DE\u767B\u3063\u305F\u9802\u70B9 (\u5B58\u5728\u3057\u306A\u3051\u308C\
    \u3070 -1)\n     */\n    long long hop(long long u, long long k) const {\n   \
    \     assert(0 <= u && u < this->size() && k >= 0);\n        if (k > this->unweighted_depth(u))\
    \ return -1;\n        for (long long i = 0; i < h; i++) {\n            if (k >>\
    \ i & 1) u = doubling_par[i][u];\n            if (u == -1) return -1;\n      \
    \  }\n        return u;\n    }\n\n    /**\n     * @brief \u6700\u5C0F\u5171\u901A\
    \u7956\u5148\n     *\n     * @param u \u9802\u70B91\n     * @param v \u9802\u70B9\
    2\n     * @return long long LCA\u306E\u9802\u70B9\u756A\u53F7\n     */\n    long\
    \ long lca(long long u, long long v) const {\n        assert(0 <= u && u < this->size()\
    \ && 0 <= v && v < this->size());\n        if (this->unweighted_depth(u) > this->unweighted_depth(v))\
    \ std::swap(u, v);\n        v = hop(v, this->unweighted_depth(v) - this->unweighted_depth(u));\n\
    \        if (u == v) return u;\n        for (long long i = h - 1; i >= 0; i--)\
    \ {\n            long long nu = doubling_par[i][u];\n            long long nv\
    \ = doubling_par[i][v];\n            if (nu == -1) continue;\n            if (nu\
    \ != nv) {\n                u = nu;\n                v = nv;\n            }\n\
    \        }\n        return this->parent_edge(u);\n    }\n\n    /**\n     * @brief\
    \ \u9802\u70B9\u9593\u8DDD\u96E2(\u91CD\u307F\u4ED8\u304D)\n     *\n     * @param\
    \ u \u9802\u70B91\n     * @param v \u9802\u70B92\n     * @return Cost u\u3068\
    v\u9593\u306E\u6700\u77ED\u7D4C\u8DEF\u306E\u8FBA\u306E\u91CD\u307F\u306E\u548C\
    \n     */\n    Cost dist(long long u, long long v) const {\n        assert(0 <=\
    \ u && u < this->size() && 0 <= v && v < this->size());\n        return this->depth(u)\
    \ + this->depth(v) - this->depth(lca(u, v)) * 2;\n    }\n\n   private:\n    void\
    \ build() {\n        long long n = this->size();\n        h = 1;\n        while\
    \ ((1LL << h) < n) h++;\n        doubling_par.assign(h, std::vector<long long>(n,\
    \ -1));\n        for (long long i = 0; i < n; i++) doubling_par[0][i] = this->parent_edge(i);\n\
    \        for (long long i = 0; i < h - 1; i++) {\n            for (long long j\
    \ = 0; j < n; j++) {\n                if (doubling_par[i][j] != -1) {\n      \
    \              doubling_par[i + 1][j] = doubling_par[i][doubling_par[i][j]];\n\
    \                }\n            }\n        }\n    }\n};\n#line 14 \"test/unittest/graph/tree-member.test.cpp\"\
    \n\ntemplate <typename T, typename = void>\nstruct has_add_directed_edge : std::false_type\
    \ {};\ntemplate <typename T>\nstruct has_add_directed_edge<T, std::void_t<decltype(std::declval<T&>().add_directed_edge(0,\
    \ 1, 1))>> : std::true_type {};\ntemplate <typename T, typename = void>\nstruct\
    \ has_add_edge : std::false_type {};\ntemplate <typename T>\nstruct has_add_edge<T,\
    \ std::void_t<decltype(std::declval<T&>().add_edge(0, 1, 1))>> : std::true_type\
    \ {};\n\nstatic_assert(has_add_directed_edge<Graph<long long>>::value);\nstatic_assert(!has_add_directed_edge<Tree<long\
    \ long>>::value);\nstatic_assert(!has_add_directed_edge<Tree<int>>::value);\n\
    static_assert(!has_add_directed_edge<RootedTree<long long>>::value);\nstatic_assert(!has_add_directed_edge<DoublingClimbTree<long\
    \ long>>::value);\nstatic_assert(has_add_edge<Tree<long long>>::value);\nstatic_assert(!has_add_edge<RootedTree<long\
    \ long>>::value);\nstatic_assert(std::is_same_v<decltype(std::declval<RootedTree<long\
    \ long>&>()[0]), const std::vector<Graph<long long>::Edge>&>);\nstatic_assert(std::is_same_v<decltype(std::declval<DoublingClimbTree<long\
    \ long>&>()[0]), const std::vector<Graph<long long>::Edge>&>);\nstatic_assert(std::is_same_v<decltype(std::declval<RootedTree<long\
    \ long>&>().parent_edge(0)), const Graph<long long>::Edge&>);\nstatic_assert(std::is_same_v<decltype(std::declval<RootedTree<long\
    \ long>&>().children(0)), const std::vector<Graph<long long>::Edge>&>);\nstatic_assert(std::is_same_v<decltype(std::declval<DoublingClimbTree<long\
    \ long>&>().preorder()), const std::vector<long long>&>);\n\nint main() {\n  \
    \  bool ok = true;\n\n    // add_edge: \u7121\u5411\u8FBA\u3068\u3057\u3066\u4E21\
    \u65B9\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u306B\u5165\u308B\n    {\n        Tree<long\
    \ long> t(4);\n        t.add_edge(0, 1, 5);\n        t.add_edge(1, 2);\n     \
    \   t.add_edge(3, 1, 7);\n        if (t.size() != 4 || t.edge_count() != 3) ok\
    \ = false;\n        if (t[1].size() != 3 || t[0].size() != 1 || t[2].size() !=\
    \ 1 || t[3].size() != 1) ok = false;\n        if (t[0][0].dst != 1 || t[0][0].cost\
    \ != 5 || t[2][0].cost != 1 || t[3][0].cost != 7) ok = false;\n        const Graph<long\
    \ long>& g = t.graph();\n        if (g.edge_count() != 3 || &g[1] != &t[1]) ok\
    \ = false;\n        if (t.set_root(0).depth(3) != 12) ok = false;\n    }\n\n \
    \   // read: n - 1 \u672C\u306E\u8FBA\u3092 1-indexed\u30FB\u91CD\u307F\u4ED8\u304D\
    \u3067\u8AAD\u3080\n    {\n        std::istringstream in(\"1 2 10\\n2 3 20\\n2\
    \ 4 30\\n\");\n        auto* old = std::cin.rdbuf(in.rdbuf());\n        Tree<long\
    \ long> t(4);\n        t.read(-1, true);\n        std::cin.rdbuf(old);\n     \
    \   auto es = t.edges();\n        if (t.edge_count() != 3 || es.size() != 3) ok\
    \ = false;\n        long long expect[3][3] = {{0, 1, 10}, {1, 2, 20}, {1, 3, 30}};\n\
    \        for (int i = 0; i < 3; i++) {\n            // \u7121\u5411\u8FBA\u306E\
    \u5411\u304D\u306F\u898F\u5B9A\u3057\u306A\u3044\u306E\u3067\u3001\u7AEF\u70B9\
    \u3092\u96C6\u5408\u3068\u3057\u3066\u6BD4\u3079\u308B\n            bool same\
    \ = (es[i].src == expect[i][0] && es[i].dst == expect[i][1]) || (es[i].src ==\
    \ expect[i][1] && es[i].dst == expect[i][0]);\n            if (!same || es[i].cost\
    \ != expect[i][2]) ok = false;\n        }\n        if (t.build_lca(0).dist(2,\
    \ 3) != 50) ok = false;\n    }\n    // read: 0-indexed\u30FB\u91CD\u307F\u306A\
    \u3057\n    {\n        std::istringstream in(\"0 1\\n0 2\\n\");\n        auto*\
    \ old = std::cin.rdbuf(in.rdbuf());\n        Tree<int> t(3);\n        t.read(0);\n\
    \        std::cin.rdbuf(old);\n        if (t.edge_count() != 2 || t[0].size()\
    \ != 2 || t[0][0].cost != 1 || t[0][1].dst != 2) ok = false;\n    }\n\n    if\
    \ (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// tree.hpp \u306E Tree \u3067\u516C\u958B\u3057\u3066\u3044\u308B\u30E1\u30F3\
    \u30D0\u3092\u691C\u8A3C\u3059\u308B\n// add_directed_edge \u306F\u5916\u304B\u3089\
    \u547C\u3079\u306A\u3044\u3053\u3068 (RootedTree\u30FBDoublingClimbTree \u3067\
    \u3082) \u3092\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u306B\u78BA\u304B\u3081\u308B\
    \n// add_edge \u3068\u3001cin \u3092\u5DEE\u3057\u66FF\u3048\u305F read \u3067\
    \u4F5C\u3063\u305F\u6728\u306E\u8FBA\u3092\u78BA\u304B\u3081\u308B\n// \u554F\u984C\
    \u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\
    \u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include <iostream>\n\
    #include <sstream>\n#include <type_traits>\n#include <utility>\n\n#include \"\
    ../../../src/graph/tree.hpp\"\n\ntemplate <typename T, typename = void>\nstruct\
    \ has_add_directed_edge : std::false_type {};\ntemplate <typename T>\nstruct has_add_directed_edge<T,\
    \ std::void_t<decltype(std::declval<T&>().add_directed_edge(0, 1, 1))>> : std::true_type\
    \ {};\ntemplate <typename T, typename = void>\nstruct has_add_edge : std::false_type\
    \ {};\ntemplate <typename T>\nstruct has_add_edge<T, std::void_t<decltype(std::declval<T&>().add_edge(0,\
    \ 1, 1))>> : std::true_type {};\n\nstatic_assert(has_add_directed_edge<Graph<long\
    \ long>>::value);\nstatic_assert(!has_add_directed_edge<Tree<long long>>::value);\n\
    static_assert(!has_add_directed_edge<Tree<int>>::value);\nstatic_assert(!has_add_directed_edge<RootedTree<long\
    \ long>>::value);\nstatic_assert(!has_add_directed_edge<DoublingClimbTree<long\
    \ long>>::value);\nstatic_assert(has_add_edge<Tree<long long>>::value);\nstatic_assert(!has_add_edge<RootedTree<long\
    \ long>>::value);\nstatic_assert(std::is_same_v<decltype(std::declval<RootedTree<long\
    \ long>&>()[0]), const std::vector<Graph<long long>::Edge>&>);\nstatic_assert(std::is_same_v<decltype(std::declval<DoublingClimbTree<long\
    \ long>&>()[0]), const std::vector<Graph<long long>::Edge>&>);\nstatic_assert(std::is_same_v<decltype(std::declval<RootedTree<long\
    \ long>&>().parent_edge(0)), const Graph<long long>::Edge&>);\nstatic_assert(std::is_same_v<decltype(std::declval<RootedTree<long\
    \ long>&>().children(0)), const std::vector<Graph<long long>::Edge>&>);\nstatic_assert(std::is_same_v<decltype(std::declval<DoublingClimbTree<long\
    \ long>&>().preorder()), const std::vector<long long>&>);\n\nint main() {\n  \
    \  bool ok = true;\n\n    // add_edge: \u7121\u5411\u8FBA\u3068\u3057\u3066\u4E21\
    \u65B9\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u306B\u5165\u308B\n    {\n        Tree<long\
    \ long> t(4);\n        t.add_edge(0, 1, 5);\n        t.add_edge(1, 2);\n     \
    \   t.add_edge(3, 1, 7);\n        if (t.size() != 4 || t.edge_count() != 3) ok\
    \ = false;\n        if (t[1].size() != 3 || t[0].size() != 1 || t[2].size() !=\
    \ 1 || t[3].size() != 1) ok = false;\n        if (t[0][0].dst != 1 || t[0][0].cost\
    \ != 5 || t[2][0].cost != 1 || t[3][0].cost != 7) ok = false;\n        const Graph<long\
    \ long>& g = t.graph();\n        if (g.edge_count() != 3 || &g[1] != &t[1]) ok\
    \ = false;\n        if (t.set_root(0).depth(3) != 12) ok = false;\n    }\n\n \
    \   // read: n - 1 \u672C\u306E\u8FBA\u3092 1-indexed\u30FB\u91CD\u307F\u4ED8\u304D\
    \u3067\u8AAD\u3080\n    {\n        std::istringstream in(\"1 2 10\\n2 3 20\\n2\
    \ 4 30\\n\");\n        auto* old = std::cin.rdbuf(in.rdbuf());\n        Tree<long\
    \ long> t(4);\n        t.read(-1, true);\n        std::cin.rdbuf(old);\n     \
    \   auto es = t.edges();\n        if (t.edge_count() != 3 || es.size() != 3) ok\
    \ = false;\n        long long expect[3][3] = {{0, 1, 10}, {1, 2, 20}, {1, 3, 30}};\n\
    \        for (int i = 0; i < 3; i++) {\n            // \u7121\u5411\u8FBA\u306E\
    \u5411\u304D\u306F\u898F\u5B9A\u3057\u306A\u3044\u306E\u3067\u3001\u7AEF\u70B9\
    \u3092\u96C6\u5408\u3068\u3057\u3066\u6BD4\u3079\u308B\n            bool same\
    \ = (es[i].src == expect[i][0] && es[i].dst == expect[i][1]) || (es[i].src ==\
    \ expect[i][1] && es[i].dst == expect[i][0]);\n            if (!same || es[i].cost\
    \ != expect[i][2]) ok = false;\n        }\n        if (t.build_lca(0).dist(2,\
    \ 3) != 50) ok = false;\n    }\n    // read: 0-indexed\u30FB\u91CD\u307F\u306A\
    \u3057\n    {\n        std::istringstream in(\"0 1\\n0 2\\n\");\n        auto*\
    \ old = std::cin.rdbuf(in.rdbuf());\n        Tree<int> t(3);\n        t.read(0);\n\
    \        std::cin.rdbuf(old);\n        if (t.edge_count() != 2 || t[0].size()\
    \ != 2 || t[0][0].cost != 1 || t[0][1].dst != 2) ok = false;\n    }\n\n    if\
    \ (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/graph/tree.hpp
  - src/graph/graph.hpp
  isVerificationFile: true
  path: test/unittest/graph/tree-member.test.cpp
  requiredBy: []
  timestamp: '2026-11-09 05:14:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/graph/tree-member.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/graph/tree-member.test.cpp
- /verify/test/unittest/graph/tree-member.test.cpp.html
title: test/unittest/graph/tree-member.test.cpp
---
