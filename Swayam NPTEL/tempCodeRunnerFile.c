for (int j = 1; j <= arr[curr1][curr2][1]; j++)
        {
            if (curr1 + j < M)
            {
                if (visited[curr1 + j][curr2] == false)
                {
                    Enqueue(q, curr1 + j, curr2);
                    visited[curr1 + j][curr2] = true;
                    printf("\nEnqueued (%u,%u)", curr1 + j, curr2);
                }
                if (curr1 + j == M - 1 && curr2 == N - 1)
                {
                    printf("\nResult:%d", log2_int(count));
                    return 0;
                }
            }
        }