
public class _743_NetworkDelayTimeSolution
{
	class Edge
	{
		public int To { get; set; }
		public int From { get; set; }
		public int Weight { get; set; }
	}

	private static List<Edge> graph = new List<Edge>();
	private static double[] distance;

	public int NetworkDelayTime(int[][] times, int n, int k)
	{
		var nodes = n;
		var edges = times.Length;

		int maxEdge = 0;

		foreach (var timeEdge in times)
		{
			graph.Add(new Edge
			{
				From = timeEdge[0],
				To = timeEdge[1],
				Weight = timeEdge[2]
			});

			var max = timeEdge[0] > timeEdge[1] ? timeEdge[0] : timeEdge[1];
			if (maxEdge < max)
			{
				maxEdge = max;
			}
		}

		var source = k;

		distance = new double[maxEdge + 1];
		Array.Fill(distance, double.PositiveInfinity);

		distance[source] = 0;

		for (int i = 0; i < nodes - 1; i++)
		{
			var updated = false;

			foreach (var edge in graph)
			{
				if (double.IsPositiveInfinity(distance[edge.From]))
				{
					continue;
				}

				var newDistance = distance[edge.From] + edge.Weight;

				if (newDistance < distance[edge.To])
				{
					distance[edge.To] = newDistance;
					updated = true;
				}

				if (!updated)
				{
					break;
				}
			}
		}

		foreach (var edge in graph)
		{
			var newDistance = distance[edge.From] + edge.Weight;

			if (newDistance < distance[edge.To])
			{
				return -1;
			}
		}

		var dist = distance.Where(x => !x.Equals(double.PositiveInfinity)).ToArray();

		return (int)dist.Max();
	}
}
