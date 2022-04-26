// Copyright 2022 Petrova Polina

#include <gtest/gtest.h>
#include <vector>
#include "../include/num_comp.h"

TEST(randTest, do_without_any_throw) {
    ASSERT_NO_THROW(int n = generateRandEdge());
}
TEST(randTest, do_number_less_two) {
    // Arrange & Act
    int n = generateRandEdge();
    EXPECT_GT(3, n);
}
TEST(graphTest, can_do_graph_without_parametrs) {
    ASSERT_NO_THROW(matrixType matrix(5));
}
TEST(graphTest, can_do_matrix_with_a_given_size_0) {
    // Arrange & Act
    matrixType matrix(7);

    // Assert
    EXPECT_EQ(7, matrix.getNumVert());
}
TEST(graphTest, can_do_matrix_with_a_given_size_1) {
    // Arrange & Act
    matrixType matrix(33);

    // Assert
    EXPECT_EQ(33, matrix.getNumVert());
}
TEST(graphTest, can_copy_graph_from_given_matrix_0) {
    // Arrenge
    std::vector<std::vector<int>> Graph;
    const int NUMVERTEX = 3;
    int matrix[NUMVERTEX][NUMVERTEX] = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    for (int i = 0; i < NUMVERTEX; i++) {
        Graph.push_back(std::vector <int>());
        for (int j = 0; j < NUMVERTEX; j++) {
            Graph[i].push_back(0);
            Graph[i][j] = matrix[i][j];
        }
    }
    // Act & Assert

    ASSERT_NO_THROW(matrixType G(NUMVERTEX, Graph));
}
TEST(graphTest, can_copy_graph_from_given_matrix_1) {
    // Arrenge
    std::vector<std::vector<int>> Graph;
    const int NUMVERTEX = 3;
    int matrix[NUMVERTEX][NUMVERTEX] = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    for (int i = 0; i < NUMVERTEX; i++) {
        Graph.push_back(std::vector <int>());
        for (int j = 0; j < NUMVERTEX; j++) {
            Graph[i].push_back(0);
            Graph[i][j] = matrix[i][j];
        }
    }
    // Act
    matrixType G(NUMVERTEX, Graph);

    // Assert
     EXPECT_EQ(3, G.getNumVert());
}
TEST(graphTest, can_do_right_matrix_0) {  // we need matrix without loop
    // Arrenge & Act
    matrixType G(3);
    std::vector<int> check;
    for (int i = 0; i < G.getNumVert(); i++) {
        for (int j = 0; j < G.getNumVert(); j++) {
            if (i == j)
                check.push_back(G(i, j));
        }
    }

    // Assert
    for (int i = 0; i < G.getNumVert(); i++)
        EXPECT_EQ(0, check[i]);
}
TEST(graphTest, can_do_right_matrix_1) {  // we need symmetrical matrix
    // Arrenge & Act
    matrixType G(7);

    // Assert
    for (int i = 0; i < G.getNumVert(); i++) {
        for (int j = 0; j < G.getNumVert(); j++) {
            if (i != j) {
                EXPECT_EQ(G(i, j), G(j, i));
            }
        }
    }
}
TEST(graphTest, operator_work_correct) {
    // Arrenge
    matrixType G(3);

    // Act & Assert
    ASSERT_NO_THROW(G(1, 1));
}
TEST(graphTest, operator_return_true_value) {
    // Arrenge
    std::vector<std::vector<int>> v {
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 7, 0, 1},
        {0, 0, 1, 0}
    };
    matrixType G(4, v);

    // Act & Assert
    EXPECT_EQ(7, G(2, 1));
}
TEST(graphTest, DFS_work_without_any_throw) {
    // Arrenge
    matrixType G(7);

    // Act & Assert
    ASSERT_NO_THROW(G.DFS(0, 5));  // 5 - flag
}
/*TEST(graphTest, DFS_work_correct) {
    // Arrenge
    matrixType G(7);

    // Act
    G.DFS(0, 5);  // 5 - flag

    // Assert
    EXPECT_EQ(7, G.used.size());
}*/
TEST(graphTest, numComp_work_without_any_throw) {
    // Arrengr & Act
    matrixType G(7);

    // Assert
    ASSERT_NO_THROW(G.numComp(5));
}
TEST(graphTest, numComp_work_correct_0) {
    // Arrenge
    std::vector<std::vector<int>> v {
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0}
    };
    matrixType G(4, v);

    // Act
    int comp = 0;
    comp = G.numComp(5);

    // Assert
    EXPECT_EQ(2, comp);
}
TEST(graphTest, numComp_work_correct_1) {
    // Arrenge
    std::vector<std::vector<int>> v {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0}
    };
    matrixType G(5, v);

    // Act
    int comp = 0;
    comp = G.numComp(5);

    // Assert
    EXPECT_EQ(2, comp);
}
TEST(graphTest, numComp_work_correct_2) {
    // Arrenge
    std::vector<std::vector<int>> v {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };
    matrixType G(6, v);

    // Act
    int comp = 0;
    comp = G.numComp(5);

    // Assert
    EXPECT_EQ(3, comp);
}
TEST(graphTest, numComp_work_correct_3) {
    // Arrenge
    std::vector<std::vector<int>> v {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };
    matrixType G(7, v);

    // Act
    int comp = 0;
    comp = G.numComp(5);

    // Assert
    EXPECT_EQ(7, comp);
}
