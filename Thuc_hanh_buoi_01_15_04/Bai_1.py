import torch
import torch.nn as nn

# Lớp Softmax thông thường
class Softmax(nn.Module):
    def __init__(self):
        super(Softmax, self).__init__()

    def forward(self, x):
        exp_x = torch.exp(x)
        sum_exp = torch.sum(exp_x)
        return exp_x / sum_exp

# Lớp Softmax ổn định số học
class softmax_stable(nn.Module):
    def __init__(self):
        super(softmax_stable, self).__init__()

    def forward(self, x):
        c = torch.max(x)
        exp_x = torch.exp(x - c)
        sum_exp = torch.sum(exp_x)
        return exp_x / sum_exp

# Ví dụ sử dụng 
print("# Examples 1")
data = torch.Tensor([1, 2, 3])

# Dùng softmax thông thường
softmax = Softmax()
output = softmax(data)
print("Output (Softmax):", output)

# Dùng softmax ổn định
softmax_stable_fn = softmax_stable()
output_stable = softmax_stable_fn(data)
print("Output (Softmax Stable):", output_stable)
