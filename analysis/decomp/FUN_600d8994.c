// 600d8994  FUN_600d8994  size=18 bytes
// --- callers ---
//   600d89ec adapter__600d89ec
//   60069964 adapter__60069964
//   60069c10 adapter__60069c10
//   600d89a6 FUN_600d89a6
//   60069780 adapter__60069780
//   60069c58 adapter__60069c58
//   60069d50 adapter__60069d50
//   60069a38 adapter__60069a38
//   60069648 adapter__60069648
//   6006988c adapter__6006988c
//   60069b20 adapter__60069b20
//   600696d0 adapter__600696d0
//   600695dc adapter__600695dc
// --- callees ---


bool FUN_600d8994(int param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_1 + 0xc);
  if (uVar1 == 0xff) {
    uVar1 = 0xffffffff;
  }
  return uVar1 == 2;
}


