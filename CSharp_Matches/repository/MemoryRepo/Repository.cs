using System.Collections.Generic;
using LabCSharp.domain;

namespace LabCSharp.repository.MemoryRepo
{
    public interface Repository<ID,E> where E:Entity<ID>
    {
        E save(E entity);
        E delete(ID id);
        E findOne(ID id);
        IEnumerable<E> findAll();
    }
}