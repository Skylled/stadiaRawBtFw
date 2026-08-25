// 600fb626  FUN_600fb626  size=96 bytes
// --- callers ---
// --- callees ---
//   600c1a34 FUN_600c1a34
//   6009afd4 FUN_6009afd4


void FUN_600fb626(int param_1,int param_2)

{
  undefined1 local_a;
  char local_9;
  
  local_a = 0x14;
  if (param_2 == 0) {
    local_9 = FUN_6009afd4(param_1 + 0x1d,0,0);
  }
  else {
    local_9 = FUN_6009afd4(param_1 + 0x1d,1,*(undefined4 *)(param_2 + 4));
  }
  if ((local_9 != '\x01') && (local_9 != '\x02')) {
    FUN_600c1a34(param_1,0x17,&local_a);
  }
  return;
}


