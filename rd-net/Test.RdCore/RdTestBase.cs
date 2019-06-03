using System;
using JetBrains.Diagnostics;
using JetBrains.Lifetimes;
using NUnit.Framework;

namespace Test.RdCore
{ 
  public abstract class RdCoreTestBase
  {
    private IDisposable myDisposable;
    
    protected LifetimeDefinition LifetimeDefinition;
    protected Lifetime TestLifetime;

    [SetUp]
    public virtual void SetUp()
    {
      myDisposable = Log.UsingLogFactory(TestLogger.Factory);
      
      LifetimeDefinition = Lifetime.Define(Lifetime.Eternal);
      TestLifetime = LifetimeDefinition.Lifetime;
    }

    [TearDown]
    public void TearDown()
    {
      TearDownInternal();
      LifetimeDefinition.Terminate();
      ThrowLoggedExceptions();
      myDisposable.Dispose();
    }
    
    protected virtual void TearDownInternal() {}

    protected void ThrowLoggedExceptions()
    {
      TestLogger.Logger.ThrowLoggedExceptions();
    }
  }
}