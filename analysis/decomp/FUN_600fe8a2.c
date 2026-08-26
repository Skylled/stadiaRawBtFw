// 600fe8a2  FUN_600fe8a2  size=116 bytes
// --- callers ---
// --- callees ---
//   600eeffa FUN_600eeffa


void FUN_600fe8a2(undefined2 *param_1,int param_2)

{
  undefined1 auStack_2bc [2];
  undefined2 uStack_2ba;
  undefined1 uStack_9;
  
  uStack_9 = 0x81;
  if ((*(int *)(param_1 + 8) != 0) && (*(int *)(*(int *)(param_1 + 8) + 0xc) != 0)) {
    uStack_9 = 0;
    FUN_600eeffa(param_1,*(undefined4 *)(param_2 + 8));
  }
  auStack_2bc[0] = uStack_9;
  uStack_2ba = *param_1;
  (*(code *)**(undefined4 **)(param_1 + 6))(6,auStack_2bc);
  return;
}


