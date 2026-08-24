// 600f1334  FUN_600f1334  size=66 bytes
// --- callers ---
//   6009c124 FUN_6009c124
// --- callees ---
//   6009c59c FUN_6009c59c
//   6009e8fc FUN_6009e8fc
//   6009c444 FUN_6009c444


void FUN_600f1334(byte param_1)

{
  if ((param_1 & 1) != 0) {
    FUN_6009c444(0);
  }
  if ((param_1 & 2) != 0) {
    FUN_6009c59c(0,0);
  }
  if ((param_1 & 4) != 0) {
    FUN_6009e8fc();
  }
  return;
}


